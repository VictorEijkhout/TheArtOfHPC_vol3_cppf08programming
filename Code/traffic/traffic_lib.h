#pragma once

#include <fmt/format.h>
#include <optional>
#include <string>
#include <tuple>
#include <vector>

/*
 * Utility functions
 */
float safe_distance( float speed );
float safe_speed( float distance );

/****
 **** Classes
 ****/

/*
 * Coordinates
 */
class coordinate : public std::pair<float,float> {
public:
  coordinate( float x,float y );
  coordinate& operator+=( const coordinate& step );
  coordinate operator*( float rate ) const;
};

/*
 * Cars
 */
class Car {
private:
  float _speed{0.f}; float goal_speed{0.f};
  coordinate _location{ coordinate(-100.f,-100.f) };
  static inline int ncars{0};
  int carno{-1};
public:
  Car() = default;
  Car( float s=1.f );
  Car( coordinate loc,float s=1.f );
  const coordinate& location() const;
  float speed() const;
  float& speed();
  void speed_adjust( float s,bool trace=false );
  void progress( const coordinate& dir );
  std::string as_string() const;
};

/*
 * Streets
 */
enum class lightcolor { red,green };

class Street : public std::vector<Car> {
 private:
  coordinate entry_point,exit_point;
 public:
  Street( coordinate a,coordinate b );
  void insert( const Car& c );
  coordinate unit_vector() const;
  float length() const;
  float displacement( const coordinate& b ) const;
  float displacement( const coordinate& b,const coordinate& a ) const;
  bool beyond( const Car& c ) const;
  bool clear_for_new_car( float speed ) const;
  void progress(bool trace=false);
  void display() const;
 private:
  std::optional< std::pair<coordinate,lightcolor> > trafficlight = {};
 public:
  void activate_light();
};

