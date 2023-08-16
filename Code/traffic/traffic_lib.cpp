// -*- c++ -*-
/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** traffic_lib.cxx : library routines for traffic simulation
 ****
 ****************************************************************/

#include "traffic_lib.hpp"

using fmt::format,fmt::print;
using std::optional;
using std::pair,std::make_pair;
using std::shared_ptr,std::make_shared;
using std::string;
using std::variant,std::get_if;
using std::vector;

#include <cmath>
#include <cassert>
using std::sqrt;

/*
 * Utility functions
 */
float safe_distance( float speed ) {
  return 2.f * speed;
};

float safe_speed( float distance ) {
  return distance / 2.f;
};

float displacement( const coordinate& b,const coordinate& a ) {
  const auto& [x1,y1] = a; const auto& [x2,y2] = b;
  auto dx = x2-x1; auto dy = y2-y1;
  return std::sqrt( dx*dx + dy*dy );
};

//! Is going from `a' -> `b' a positive step along `n'?
float displacement( const coordinate& a,const coordinate& b,const coordinate& n ) {
  const auto& [x1,y1] = a; const auto& [x2,y2] = b;
  auto dx = x2-x1; auto dy = y2-y1;
  auto [nx,ny] = n;
  bool same_direction = ( dx*nx >= 0.f ) and ( dy*ny >= 0.f );
  return std::sqrt( dx*dx + dy*dy ) * ( same_direction ? +1 : -1 ) ;
};

/*
 * Coordinates
 */

coordinate::coordinate( float x,float y )
  : pair<float,float>(x,y) {};
coordinate& coordinate::operator+=( const coordinate& step ) {
  auto& [x,y] = *this;
  auto [dx,dy] = step;
  x += dx; y += dy;
  return *this;
};
coordinate coordinate::operator+( const coordinate& step ) const {
  auto& [x,y] = *this;
  auto [dx,dy] = step;
  return coordinate( x+dx, y+dy );
};
coordinate coordinate::operator*( float rate ) const {
  const auto [x,y] = *this;
  return coordinate( x*rate,y*rate );
};

/*
 * Cars
 */

Car::Car( car_state s ) :
  current_state(s) {
  carno = ncars++;
};

Car::Car( coordinate loc,float s )
  : Car( { .speed=s,.goal_speed=s,.location=loc } ) {
};
Car::Car( float s )
  : Car( {.speed=s,.goal_speed=s} ) {
};

/*
 * Accessors
 */
const coordinate& Car::location() const {
  return current_state.location;
};

float Car::speed() const {
  return current_state.speed; };
float Car::acceleration() const {
  return current_state.acceleration; };
// float& Car::speed() {
//   return current_state.speed; };

void Car::set_forced_speed( vector<float> speeds ) {
  forced_speed = speeds;
};

float Car::displacement( const Car& other,const coordinate& normal ) const {
  return ::displacement(location(),other.location(),normal);
};

Car& Car::set_risk_tolerance( float tol ) {
  risk_tolerance = tol;
  return *this;
};

void Car::determine_next_state(bool trace) {
  /*
   * What speed are we aiming for by ourselves?
   */
  float aim_for_speed;
  if ( not forced_speed.empty() ) {
    float s = forced_speed.front();
    forced_speed.erase( forced_speed.begin() );
    aim_for_speed = s;
  } else
    aim_for_speed = current_state.goal_speed;
  /*
   * Is our speed dictated by a car ahead?
   */
  if (infront!=nullptr) {
    aim_for_speed = std::min( aim_for_speed, safe_following_speed( *infront ) );
  }
  /*
   * Slowly accelerate to that aimed speed
   */
  float next_speed = speed_adjust(aim_for_speed,trace);
  next_state = current_state;
  next_state.speed = next_speed;
};

// determine a following speed based on the car ahead of you
// but if you're risk tolerance: set speed as if you're much further apart
float Car::safe_following_speed( const Car& next_car ) const {
  auto disp = ::displacement( next_car.location(),location() );
  disp *= risk_tolerance;
  return safe_speed(disp);
};

float Car::safe_following_distance( const Car& next_car ) const {
  auto speed = next_car.speed();
  auto time = speed / acceleration();
  auto dist = .5f * acceleration() * time*time;
  return dist;
};

float Car::speed_adjust( float s,bool trace ) {
  float
    cur_speed = current_state.speed,
    new_speed = current_state.speed;
  float accel = current_state.acceleration;
  assert(accel>=0.f);
  if (s<cur_speed) {
    new_speed = std::max( s,cur_speed-accel );
    if (new_speed<.5 and s==0) new_speed = 0;
    if (trace)
      print( "setting speed to {} - {} = {}\n",
	     cur_speed,accel,new_speed);
  } else if (s>cur_speed) {
    new_speed = std::min( s,current_state.goal_speed+accel );
    if (trace)
      print( "Car {}: recovering speed from {} to {}, goal={}\n",
	     carno,cur_speed,new_speed,current_state.goal_speed);
  }
  return new_speed;
};

bool Car::collides_with( const Car& other,const coordinate& unit ) {
  auto d = ::displacement( location(),other.location(),unit );
  //  print( "collision displacement: {}\n",d );
  return d<=0;
};

void Car::progress( const coordinate& dir ) {
  current_state = next_state;
  current_state.location += dir * current_state.speed;
};

/*
 * Output
 */
void Car::set_render( char x ) {
  render = x;
}
string Car::as_string() const {
  auto [x,y] = current_state.location;
  return format("Car{}=({},{}) s={}",carno,x,y,current_state.speed);
}

/*
 * Streets
 */

Street::Street( coordinate a,coordinate b )
  : entry_point(a),exit_point(b) {};

int Street::ncars() const {
  return vector<shared_ptr<Car>>::size();
};

const vector<shared_ptr<Car>>& Street::cars() const {
  return *this;
};

void Street::activate_light() {
  trafficlight = make_pair( coordinate( exit_point ), lightcolor::green );
};

coordinate Street::unit_vector() const {
  const auto& [x1,y1] = entry_point; const auto& [x2,y2] = exit_point;
  auto dx = x2-x1; auto dy = y2-y1; auto r = std::sqrt( dx*dx + dy*dy );
  return coordinate( dx/r, dy/r );
};

/* beginning and and of the street */

float Street::length() const {
  return displacement(exit_point); }
// single parameter displacement is wrt start of the street
float Street::displacement( const coordinate& b ) const {
  return ::displacement(b,entry_point);
}

bool Street::beyond( shared_ptr<Car> c ) const {
  auto d = displacement(c->location());
  return d >= displacement(exit_point) or d<=0.f;
};

/*
 * street action
 */
bool Street::is_clear_for_new_car( float speed ) const {
  return displacement( front()->location() ) > safe_distance( speed );
};

void Street::insert_with_speed( float speed ) {
  auto newcar = make_shared<Car>
    ( car_state{ .speed=speed,.goal_speed=speed,.location=entry_point, .acceleration=speed/5} );
  if (ncars()>0) {
    newcar->infront = front();
    front()->inback   = newcar;
  }
  vector<shared_ptr<Car>>::insert( begin(), newcar );
};

bool Street::progress(bool trace) {
  if (trace) print("==== Progress step ====\n");
  /*
   * Set new speed and acceleration for all cars
   * This is stored internally as the `next state'.
   */
  for ( auto carptr : *this ) {
    carptr->determine_next_state(trace);
  }
  /*
   * Every car installs next state as current state
   * and moves a little based on the new speed
   */
  //codesnippet streetmovecars
  for ( auto c : cars() ) {
    c->progress( unit_vector() );
  }
  //codesnippet end
  /*
   * Any accidents?
   */
  if ( detect_collisions() )
    return false;

  /*
   * We remove cars that have left the end point
   */
  for ( ;; ) {
    if (empty()) break;
    if ( beyond(back()) ) {
      pop_back();
      if (not empty())
	back()->infront = nullptr;
    } else
      // we assume that the list is sorted
      // so if the last one is not beyond:
      break;
  }
  return true;
};

//! See if any car has run into the one before it
bool Street::detect_collisions() {
  bool collision = false;
  for ( const auto& carptr : * this ) {
    auto next = carptr->infront;
    if (next==nullptr) break;
    if (carptr->collides_with(*next,unit_vector()))
      return true;
  }
  return false;
};

string Street::as_string() const {
  const int maxloc = 132;
  auto stretch = maxloc/length();
  string render(maxloc,' ');
  for ( const auto& carptr : *this ) {
    int relative_loc = displacement( carptr->location() ) * stretch;
    render.at(relative_loc) = carptr->render;
  }
  return render;
}
void Street::display() const {
  const int maxloc = 132; // duplicate!
  // cursor left by n : ESC [ Pn D
  // so maxloc should be left margin
  printf( "%c[%dD",(char)27,maxloc);
  auto render = as_string();
  printf( "%s",render.c_str() );
};
