// -*- c++ -*-
/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** traffic_lib.h : headers for traffic simulation
 ****
 ****************************************************************/

#pragma once

#include <fmt/format.h>
#include <memory>
#include <optional>
#include <string>
#include <tuple>
#include <vector>
#include <variant>

/*
 * Utility functions
 */
float safe_distance( float speed );
float safe_speed( float distance );
class coordinate;
float displacement( const coordinate& b,const coordinate& a );
float displacement( const coordinate& b,const coordinate& a,const coordinate&n );

/****
 **** Classes
 ****/

/*
 * Coordinates
 *
 * this inheritance stuff triggers an ABI warning in GCC
 * https://stackoverflow.com/a/52391447/2044454
 */
class coordinate : public std::pair<float,float> {
public:
  coordinate( float x,float y );
  coordinate operator+( const coordinate& step ) const;
  coordinate& operator+=( const coordinate& step );
  coordinate operator*( float rate ) const;
};

// Describe what a car is doing
// Having this as a struct makes it easier to copy
struct car_state {
  float speed{0.f};
  float goal_speed{-1.f}; // set to illegal value
  coordinate location{ coordinate(-100.f,-100.f) };
  float acceleration{0.f};
};

/*
 * Cars
 */
class Street;
class Car {
  friend class Street;
private:
  // double linked list of cars in a street
  std::shared_ptr<Car> infront{nullptr},inback{nullptr};

  // global bookkeeping of cars
  static inline int ncars{0};
  int carno{-1};
public:
  Car() = default;
  Car( car_state );
  Car( float s=1.f );
  Car( coordinate loc,float s=1.f );

  void progress(bool trace=false);
  void determine_next_state( bool trace=false );
  //! See if this car has run into the other, given a displacement vector
  bool collides_with( const Car& other,const coordinate& unit );

  /*
   * State
   */
private:
  // basic data on where we are, where we are going, what we do
  car_state current_state,next_state;
public:
  const coordinate& location() const;
  float speed() const;
  // float& speed()
  float acceleration() const;
  float displacement( const Car& other,const coordinate& normal ) const;

  /*
   *Manipulation
   */
private:
  std::vector<float> forced_speed;
public:
  void set_forced_speed( std::vector<float> );
  float safe_following_speed( const Car& next_car ) const;
  float safe_following_distance( const Car& next_car ) const;
  float speed_adjust( float s,bool trace=false );
  void progress( const coordinate& dir );
private:
  // divide safe distance by risk tolerance
  float risk_tolerance{1.f};
public:
  Car& set_risk_tolerance( float tol );
private:
  char render{'x'};
public:
  void set_render( char x );
  std::string as_string() const;
};

/*
 * Streets
 */
enum class lightcolor { red,green };

class Street : public std::vector<std::shared_ptr<Car>> {
 private:
  coordinate entry_point,exit_point;
 public:
  Street( coordinate a,coordinate b );
  int ncars() const;
  const vector<std::shared_ptr<Car>>& cars() const;
  //  void insert( const Car& c );
  void insert_with_speed( float speed );
  coordinate unit_vector() const;
  float length() const;
  float displacement( const coordinate& b ) const;
  bool beyond( std::shared_ptr<Car> c ) const;
  bool is_clear_for_new_car( float speed ) const;
  bool progress(bool trace=false);
  bool detect_collisions();
  std::string as_string() const;
  void display() const;
 private:
  std::optional< std::pair<coordinate,lightcolor> > trafficlight = {};
 public:
  void activate_light();
};

