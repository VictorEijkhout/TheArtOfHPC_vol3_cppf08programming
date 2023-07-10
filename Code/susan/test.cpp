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

#include <vector>
using std::vector;

//codesnippet tddtester
#include "functions.hpp"

#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

TEST_CASE( "test the increment function" ) {
  //codesnippet end
  //codesnippet tddpos
  for (int i=1; i<10; ++i)
    REQUIRE( increment_positive_only(i)==i+1 );
  //codesnippet end
  //codesnippet tddneg
  for (int i=0; i>-10; i--)
    REQUIRE_THROWS( increment_positive_only(i) );
  //codesnippet end
//codesnippet tddtester
}
//codesnippet end
