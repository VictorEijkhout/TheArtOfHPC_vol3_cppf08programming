#include "traffic_lib.h"

using fmt::format,fmt::print;
using std::optional;
using std::pair,std::make_pair;
using std::string;
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
coordinate coordinate::operator*( float rate ) const {
  const auto [x,y] = *this;
  return coordinate( x*rate,y*rate );
};

/*
 * Cars
 */

Car::Car( coordinate loc,float s )
  : Car(s) {
  _location = loc;
  carno = ncars++;
};
Car::Car( float s )
  : _speed(s),goal_speed(s) {
};
const coordinate& Car::location() const {
  return _location;
};

float Car::speed() const { return _speed; };
float& Car::speed() { return _speed; };

void Car::speed_adjust( float s,bool trace ) {
  float new_speed = _speed;
  if (s<_speed) {
    new_speed = s;
    if (trace) print( "setting speed to {}\n",new_speed);
  } else if (s>_speed) {
    auto goal = std::min( s,goal_speed );
    new_speed = (goal+_speed)/2;
    if (trace)
      print( "Car {}: recovering speed from {} to {}, goal={}\n",
	     carno,_speed,new_speed,goal_speed);
  }
  assert( new_speed<=goal_speed );
  _speed = new_speed;
};
void Car::progress( const coordinate& dir ) {
  _location += dir * _speed;
};
string Car::as_string() const {
  auto [x,y] = _location;
  return format("Car{}=({},{}) s={}",carno,x,y,_speed);
}

/*
 * Streets
 */

Street::Street( coordinate a,coordinate b )
  : entry_point(a),exit_point(b) {};

void Street::insert( const Car& c ) {
  // need to keep sorted?
  vector<Car>::insert( begin(), Car(entry_point,c.speed()) );
  //  push_back( Car(entry_point,c.speed()) );
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
  return displacement(b,entry_point);
}
float Street::displacement( const coordinate& b,const coordinate& a ) const {
  const auto& [x1,y1] = a; const auto& [x2,y2] = b;
  auto dx = x2-x1; auto dy = y2-y1;
  return std::sqrt( dx*dx + dy*dy );
};
bool Street::beyond( const Car& c ) const {
  auto d = displacement(c.location());
  return d >= displacement(exit_point) or d<=0.f;
};

bool Street::clear_for_new_car( float speed ) const {
  return displacement( front().location() ) > safe_distance( speed );
};

void Street::progress(bool trace) {
  // adapting max speed to distance
  for ( int icar=0; icar<size()-1; icar++ ) {
    auto& this_car = at(icar);
    const auto& next_car = at(icar+1);
    auto disp = displacement( next_car.location(),this_car.location() );
    auto speed = safe_speed(disp);
    this_car.speed_adjust(speed,trace);
  }
  // every car moves a little
  for ( auto& c : *this ) {
    c.progress( unit_vector() );
  }
  // we remove cars that have left the end point
  for ( ;; ) {
    if (empty()) break;
    if ( beyond(back()) )
      pop_back();
    else
      // we assume that the list is sorted
      // so if the last one is not beyond:
      break;
  }
};

void Street::display() const {
  const int maxloc = 132;
  auto stretch = maxloc/length();
  // cursor left by n : ESC [ Pn D
  // so maxloc should be left margin
  printf( "%c[%dD",(char)27,maxloc);
  int current_loc=0;
  for ( const auto& c : *this ) {
    int relative_loc = displacement( c.location() ) * stretch;
    int d = relative_loc-current_loc;
    for ( int i=0; i<d; i++) printf(" ");
    printf("x");
    current_loc = relative_loc+1;
  }
  for ( ; current_loc<maxloc; current_loc++ )
    printf(" ");
};
