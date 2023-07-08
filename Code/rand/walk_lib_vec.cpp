/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2020-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** walk_lib.css :  random walks library using std::vector
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;
#include <ostream>
using std::ostream;

#include<algorithm>
using std::for_each;

#include <limits>

#include <random>

#include <vector>
using std::vector;

#include <cassert>

ostream &operator<<(ostream &os,const vector<float> &v) {
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

float length( const vector<float>& step ) {
  vector<float> square;
  int s = step.size();
  if (square.size()!=s) square.resize(s);
  for ( int i=0; i<s; i++) square[i] = step[i];
  for_each( square.begin(),square.end(),
	    [] (float& x) { x *= x; } );
  auto l = sqrt
    ( accumulate( square.begin(),square.end(),0.f ) );
  return l;
};

void normalize( vector<float>& step,float len=0.f ) {
  if (len==0.f)
    len = length(step);
  if (len==0.f)
    cout << "Zero vector size " << step.size() << ": " << step << '\n';
  assert( len!=0.f );
  for_each( step.begin(),step.end(),
	    [len] (float& x) { x /= len; } );
};

bool no_nans( const vector<float>& step ) {
  bool ok{true};
  for_each( step.begin(),step.end(),
	    [&ok] (float x) { ok = ok and not std::isnan(x); } );
  return ok;
};

//codesnippet walkrandcoord
vector<float> random_coordinate( int d ) {
  auto v = vector<float>(d);
  for ( auto& e : v )
    e = random_float();
  return v;
};
//codesnippet end

//codesnippet walkrandstep
vector<float> random_step(int d) {
  for (;;) {
    auto step = random_coordinate(d);
    if ( auto l=length(step); l<=1.f ) {
      if ( l==0.f ) {
	/*
	 * Zero lengths can conceivably happen for d==1
	 * but should not for higher d.
	 */
	assert(d==1);
      } else {
	normalize(step,l);
	return step;
      }
    }
  }
};
//codesnippet end

//codesnippet mosqclass
class Mosquito {
private:
  vector<float> pos;
public:
  Mosquito( int d )
    : pos( vector<float>(d,0.f) ) { };
//codesnippet end
  Mosquito( vector<float> pos )
    : pos(pos) {};
  //codesnippet walkstep
  void step() {
    int d = pos.size();
    auto incr = random_step(d);
    for (int id=0; id<d; id++)
      pos.at(id) += incr.at(id);
  };
  //codesnippet end
  float distance() const {
    return length(pos);
  };
};

