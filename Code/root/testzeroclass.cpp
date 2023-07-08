/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** testzero.cxx : unittests for root finding
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <iomanip>
using std::setw;

#include <vector>
using std::vector;

#include "findzeroclass.hpp"

#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

TEST_CASE( "proper test","[2]" ) {
  vector<double> coefficients{3.,2.,0.,1.1};
  polynomial p(coefficients);
  REQUIRE( p.is_proper() );
  coefficients.at(0) = 0.;
  polynomial q(coefficients);
  REQUIRE( not q.is_proper() );
}

TEST_CASE( "polynomial degree","[3]" ) {
    polynomial second( {2,0,1} ); // 2x^2 + 1
  REQUIRE( not second.is_odd() );
  polynomial third( {3,2,0,1} ); // 3x^3 + 2x^2 + 1
  REQUIRE( third.is_odd() );
}

TEST_CASE( "polynomial evaluation","[4]" ) {
  //codesnippet rootcatcheval
  polynomial second( {2,0,1} ); 
  // correct interpretation: 2x^2 + 1
  REQUIRE( second.is_proper() );
  REQUIRE( second.evaluate_at(2) == Catch::Approx(9) );
  // wrong interpretation: 1x^2 + 2
  REQUIRE( second.evaluate_at(2) != Catch::Approx(6) );
  //codesnippet end
  REQUIRE( second.evaluate_at(2) == Catch::Approx(9) );
  polynomial third( {3,2,0,1} ); // 3x^3 + 2x^2 + 1
  REQUIRE( third.is_proper() );
  REQUIRE( third.evaluate_at(0) == Catch::Approx(1) );
}

TEST_CASE( "outer bounds","[5]" ) {
  double left{10},right{11};
  right = left+1;
  polynomial second( {2,0,1} ); // 2x^2 + 1
  REQUIRE_THROWS( second.find_initial_bounds(left,right) );
  polynomial third( {3,2,0,1} ); // 3x^3 + 2x^2 + 1
  REQUIRE_NOTHROW( third.find_initial_bounds(left,right) );
  REQUIRE( left<right );
  double
    leftval = third.evaluate_at(left),
    rightval = third.evaluate_at(right);
  REQUIRE( leftval*rightval<=0 );
}

TEST_CASE( "outer bounds loop","[5]" ) {
  for ( auto c : vector<vector<double>>{
      {1., 0., 0., 0.}, {.01, 0., 0., 0., 0., 100000.}
    } ) {
    polynomial oddpoly( c );
    double left{10},right{11};
    REQUIRE_NOTHROW( oddpoly.find_initial_bounds(left,right) );
    REQUIRE( left<right );
    double
      leftval = oddpoly.evaluate_at(left),
      rightval = oddpoly.evaluate_at(right);
    REQUIRE( leftval*rightval<=0 );
  }
}

TEST_CASE( "move bounds closer","[6]" ) {
  double left{10},right{11};
  polynomial third( {3,2,0,1} ); // 3x^3 + 2x^2 + 1
  REQUIRE_NOTHROW( third.find_initial_bounds(left,right) );
  double
    leftval = third.evaluate_at(left),
    rightval = third.evaluate_at(right);
  REQUIRE( leftval*rightval<=0 );
  REQUIRE_THROWS( third.move_bounds_closer(right,left) );
  REQUIRE_THROWS( third.move_bounds_closer(left,left) );
  double old_left = left, old_right = right;
  REQUIRE_NOTHROW( third.move_bounds_closer(left,right) );
  leftval = third.evaluate_at(left);
  rightval = third.evaluate_at(right);
  REQUIRE( leftval*rightval<=0 );
  REQUIRE( ( ( left==old_left and right<old_right ) or
	     ( right==old_right and left>old_left ) ) );
}

TEST_CASE( "test zero finder", "[7]" ) {
  vector<vector<double>> coefficients{
    {1., 0., 0., 0.01}, // x^3, 3x^2
    {.01, 0., 0., 0., 0., 100000.} // 1/100 x^5 + 10,000 , 1/20 x^4
  };
  for ( int ipoly=0; ipoly<coefficients.size(); ipoly++ ) {
    polynomial oddpoly(coefficients.at(ipoly));
    INFO( "polynomial #" << ipoly );
    double zero, value, prec=1.e-5;
    REQUIRE_NOTHROW( zero = oddpoly.find_zero(prec) );
    INFO( "found zero=" << zero );
    REQUIRE_NOTHROW( value = oddpoly.evaluate_at(zero) );
    REQUIRE( abs(value)<prec );
  }
}
