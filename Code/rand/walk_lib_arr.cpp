/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2020-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** walk_lib.css :  random walks library
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;
#include <ostream>
using std::ostream;

#include<algorithm>
using std::for_each;

#include <limits>
#include <numeric>
#include <random>

#include <array>
using std::array;

#include <cassert>

template<int d>
ostream &operator<<(ostream &os,const array<float,d> &v) {
  os << "(";
  for ( auto e : v )
    os << e << ",";
  os << ")";
return os;
};

float random_float() {
  static std::random_device r;
  static std::default_random_engine static_engine( r() );
  std::uniform_real_distribution<float> distribution(-1.f,1.f);
  return distribution(static_engine);
};

//codesnippet walklenghtarr
template<int d>
float length( const array<float,d>& step ) {
  array<float,d> square = step;
  for_each( square.begin(),square.end(),
	    [] (float& x) { x *= x; } );
  auto l = sqrt
    ( std::accumulate( square.begin(),square.end(),0.f ) );
  return l;
};
//codesnippet end

template<int d>
array<float,d> normalize( array<float,d> step,float len=0.f ) {
  if (len==0.f)
    len = length<d>(step);
  // if (len==0.f)
  //   cout << "Zero array size " << step.size() << ": " << step << '\n';
  assert( len!=0.f );
  for_each( step.begin(),step.end(),
	    [len] (float& x) { x /= len; } );
  return step;
};

template<int d>
bool no_nans( const array<float,d>& step ) {
  bool ok{true};
  for_each( step.begin(),step.end(),
	    [&ok] (float x) { ok = ok and not std::isnan(x); } );
  return ok;
};

template<int d>
array<float,d> random_coordinate() {
  auto v = array<float,d>();
  for ( auto& e : v )
    e = random_float();
  return v;
};

template<int d>
array<float,d> random_step() {
  for (;;) {
    auto step = random_coordinate<d>();
    if ( auto l=length<d>(step); l<=1.f ) {
      if (l==0.f) {
	/*
	 * Zero lengths can conceivably happend for d==1
	 * but should not for higher d.
	 */
	// cout << "Zero length for " << step << '\n';
	assert(d==1);
      } else {
	step = normalize<d>(step,l);
	return step;
      }
    }
  }
};

template<int d>
class Mosquito {
private:
  array<float,d> pos;
public:
  Mosquito() { for ( auto& c : pos ) c = 0.f; };
  //   : pos( array<float,d>(0.f) ) {};
  // Mosquito( array<float,d> pos )
  //   : pos(pos) {};
  void step() {
    auto incr = random_step<d>();
    step( incr );
  };
  void step( const array<float,d>& incr ) {
    for (int id=0; id<d; ++id)
      pos.at(id) += incr.at(id);
  };
  float distance() const {
    return length<d>(pos);
  };
};

