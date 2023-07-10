/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2020-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** walk_test.css :  random walks unit tests
 ****
 ****************************************************************/

#include <cmath>

#include "walk_lib.cpp"

#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

TEST_CASE( "random numbers" ) {
  int np=0,nm=0;
  const int steps=1000;
  for (int i=0; i<steps; ++i) {
    auto v = random_float();
    np += (v>0);
    nm += (v<0);
  }
  REQUIRE( np>0 );
  REQUIRE( nm>0 );
  REQUIRE( np>steps/4 );
  REQUIRE( nm>steps/4 );

  vector<float> v;
  REQUIRE_NOTHROW( v = random_coordinate(5) );
  for (int i=0; i<v.size()-1; ++i)
    REQUIRE( v[i]!=v[i+1] );
};

TEST_CASE( "random stepping" ) {
  for ( auto d : {1,2,3,4} ) {
    INFO( "d=" << d );
    for ( int s=0; s<1000000; ++s) {
      INFO( "step=" << s );
      auto step = random_step(d);
      bool ok = no_nans(step);
      REQUIRE( ok );
    }
  }
};

TEST_CASE( "normalization stuff" ) {
  vector<float> three{1.f,1.f,1.f};
  float l;
  REQUIRE_NOTHROW( l = length(three) );
  REQUIRE( l==Catch::Approx( sqrt(3) ) );

  vector<float> v{1.f,0.f,0.f},vv;
  REQUIRE_NOTHROW( vv = normalize(v) );
  REQUIRE( vv[0]==Catch::Approx(1.f) );

  v = {1.f,1.f};
  REQUIRE( length(v)==Catch::Approx(sqrt(2.)) );
  REQUIRE_NOTHROW( vv = normalize(v) );
  REQUIRE( vv[0]==Catch::Approx( sqrt(2)/2 ) );
  REQUIRE( vv[1]==Catch::Approx( sqrt(2)/2 ) );
  REQUIRE( length(vv)==Catch::Approx(1.) );

  v = {-1.f,-1.f};
  REQUIRE( length(v)==Catch::Approx(sqrt(2.)) );
  REQUIRE_NOTHROW( vv = normalize(v) );
  REQUIRE( vv[0]==Catch::Approx( -sqrt(2)/2 ) );
  REQUIRE( vv[1]==Catch::Approx( -sqrt(2)/2 ) );
  REQUIRE( length(vv)==Catch::Approx(1.) );
};

TEST_CASE( "mosquito stuff" ) {
  Mosquito one( {1.f,1.f,1.f} );
  REQUIRE_NOTHROW( one.step( {-2,-2,-2} ) );
  REQUIRE( one.distance()==Catch::Approx( sqrt(3) ) );
};

