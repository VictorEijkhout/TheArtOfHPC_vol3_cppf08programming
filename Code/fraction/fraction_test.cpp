/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** fraction_test.cxx : unit tests for fractions
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <iomanip>
using std::fixed;
using std::setprecision;

#include <vector>
using std::vector;
#include <chrono>
#include <optional>
using std::optional;

#include "fractionlib.hpp"

#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

TEST_CASE( "gcd testing" ) {
  REQUIRE( gcd(5,0)==5 );
  REQUIRE( gcd(0,6)==6 );
  REQUIRE( gcd(7,7)==7 );

  REQUIRE( gcd(-5,0)==5 );
  REQUIRE( gcd(0,-6)==6 );
  REQUIRE( gcd(-7,-7)==7 );
}

TEST_CASE( "simplification" ) {
  auto s = Fraction(1,4);
  REQUIRE( s.numerator()==1 );
  REQUIRE( s.denominator()==4 );

  auto t = Fraction(2,4);
  REQUIRE( t.numerator()==1 );
  REQUIRE( t.denominator()==2 );

  auto u = Fraction(9*11,10*11);
  REQUIRE( u.numerator()==9 );
  REQUIRE( u.denominator()==10 );
}

TEST_CASE( "equvality" ) {
  REQUIRE( Fraction(2,5)==Fraction(4,10) );
  REQUIRE( Fraction(2,5)!=Fraction(3,5) );
}

TEST_CASE( "multiply by integer" ) {
  auto half = Fraction(1,2);
  auto one = half * 2;
  REQUIRE( one.numerator()==1 );
  REQUIRE( one.denominator()==1 );
}

TEST_CASE( "addition" ) {
  auto half = Fraction(1,2);
  auto fivesix = Fraction(5,6);
  auto sum = half+fivesix;
  INFO( "sum " << sum );
  REQUIRE( sum.numerator()==4 );
  REQUIRE( sum.denominator()==3 );
}
