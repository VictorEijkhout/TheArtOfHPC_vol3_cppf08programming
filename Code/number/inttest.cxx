/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** inttest.cxx : unit testing the integer library
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

#include "intlib.h"

#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

TEST_CASE( "small numbers" ) {
  SECTION( "Base 10" ) {
    const int base = 10;
    BigInt<base> zero(0);
    REQUIRE( zero.ndigits()==0 );
    REQUIRE_NOTHROW( zero.numeric()==0 );
    REQUIRE( zero==0 );

    BigInt<base> one(1);
    REQUIRE( one.ndigits()==1 );
    REQUIRE_NOTHROW( one.numeric()==1 );
  }
  SECTION( "Base 1000" ) {
    const int base=1000;
    BigInt<base> zero(0);
    REQUIRE( zero.ndigits()==0 );
    REQUIRE_NOTHROW( zero.numeric()==0 );
    REQUIRE( zero==0 );

    BigInt<base> one(1);
    REQUIRE( one.ndigits()==1 );
    REQUIRE_NOTHROW( one.numeric()==1 );
  }
}

TEST_CASE( "more numbers" ) {
  SECTION( "Base 1000" ) {
    const int base=1000;
    BigInt<base> lots( 3*base+5);
    REQUIRE( lots.ndigits()==2 );
    REQUIRE( lots.leading_digit()==3 );
    REQUIRE_NOTHROW( lots==3*base+5 );
  }
  SECTION( "Base 10" ) {
    const int base=10;
    for ( auto n : { 1, 12, 123, 1234, 12345 } ) {
      INFO( "Big Int: " << n );
      BigInt<base> bigint;
      REQUIRE_NOTHROW( bigint = BigInt<base>(n) );
      REQUIRE( bigint==n );
    }
  }
}

TEST_CASE( "summing" ) {
  const int base=1000;
  BigInt<base> result;
  int one3 = base/3, one5 = base/5;
  REQUIRE_NOTHROW( result = BigInt<base>(one3) + BigInt<base>(one5) );
  REQUIRE( result==one3+one5 );
  // make sure either order works
  int three4 = 3*base/4;
  SECTION ("lr") { REQUIRE_NOTHROW( result = BigInt<base>(three4) + BigInt<base>(one3) ); }
  SECTION ("rl") { REQUIRE_NOTHROW( result = BigInt<base>(one3) + BigInt<base>(three4) ); }
  REQUIRE( result.ndigits()==2 );
  REQUIRE( result==three4+one3 );
}

TEST_CASE( "multiplication" ) {
  const int base=1000;
  BigInt<base> small(100);
  BigInt<base> product;
  REQUIRE_NOTHROW( product = small*5 );
  REQUIRE( product==500 );
  REQUIRE_NOTHROW( product = small*50 );
  REQUIRE( product==5000 );
  int bm1 = base-1;
  BigInt<base> b_bm1( bm1 );
  REQUIRE_NOTHROW( product=b_bm1*bm1 );
  REQUIRE( product==bm1*bm1 );
  int bm2 = base-2;
  BigInt<base> b_bm2( bm2 );
  REQUIRE_NOTHROW( product=b_bm2*bm2 );
  REQUIRE( product==bm2*bm2 );
  REQUIRE_NOTHROW( product=product*product );
}

TEST_CASE( "subtraction" ) {
  SECTION( "Borrowing" ) {
    const int base=10;
    BigInt<base> n(23);
    REQUIRE_NOTHROW( n.borrow(0) );
    REQUIRE( n.digit(0)==13 );
    REQUIRE( n.digit(1)==1 );
  }
  SECTION( "Base 10" ) {
    const int base=10;
    BigInt<base> thousand(1000),one(1);
    BigInt<base> nine99;
    REQUIRE_NOTHROW( nine99 = thousand-1 );
    INFO( "nine nine nine = " << nine99.numeric() );
    REQUIRE( nine99.ndigits()==3 );
    REQUIRE( nine99==999 );
  }
  SECTION( "Base 1000" ) {
    const int base=1000;
    BigInt<base> x(50),y(45),z;
    REQUIRE_NOTHROW( z = x-y );
    REQUIRE( z==5 );
    BigInt<base> thousand(1000),one(1),nine,notnine;
    REQUIRE( thousand.ndigits()==2 );
    REQUIRE_THROWS( notnine=one-thousand );
    REQUIRE_NOTHROW( nine=thousand-one );
    REQUIRE( nine==999 );
    REQUIRE( nine.ndigits()==1 );
  }
}

TEST_CASE( "division" ) {
  const int base=10;
  BigInt<base> fiftyone(51),ten(10);
  auto [five,one] = fiftyone/ten;
}
