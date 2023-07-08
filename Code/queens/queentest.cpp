/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** queentest.cpp : unittests for 8-queens
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

#include "queens.hpp"

#ifndef NQUEENS
#define NQUEENS 8
#endif

#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

//codesnippet qtempty
TEST_CASE( "empty board","[1]" ) {
  constexpr int n=10;
  ChessBoard empty(n);
  REQUIRE( empty.next_row_to_be_filled()==0 );
}
//codesnippet end

TEST_CASE( "bounds test","[2]" ) {
  constexpr int n=10;
  ChessBoard empty(n);
  //codesnippet qtfillfirst
  REQUIRE_THROWS( empty.place_next_queen_at_column(-1) );
  REQUIRE_THROWS( empty.place_next_queen_at_column(n) );
  REQUIRE_NOTHROW( empty.place_next_queen_at_column(0) );
  REQUIRE( empty.next_row_to_be_filled()==1 );
  //codesnippet end
}

TEST_CASE( "feasibility test","[3]" ) {
  constexpr int n=10;
  //codesnippet qtfeasible0
  ChessBoard empty(n);
  REQUIRE( empty.feasible() );
  //codesnippet end

  //codesnippet qtfeasible1
  ChessBoard one = empty;
  one.place_next_queen_at_column(0);
  REQUIRE( one.next_row_to_be_filled()==1 );
  REQUIRE( one.feasible() );
  //codesnippet end
}

TEST_CASE( "collision test","[4]" ) {
  constexpr int n=10;
  ChessBoard empty(n);
  ChessBoard one = empty;
  one.place_next_queen_at_column(0);
  //codesnippet qtcollide
  ChessBoard collide = one;
  // place a queen in a `colliding' location
  collide.place_next_queen_at_column(0);
  // and test that this is not feasible
  REQUIRE( not collide.feasible() );
  //codesnippet end
}

TEST_CASE( "final test","[5]" ) {
  //codesnippet qtsolution5
  ChessBoard five( {0,3,1,4,2} );
  REQUIRE( five.feasible() );
  //codesnippet end
  REQUIRE( five.filled() );
}

TEST_CASE( "generate one and two","[6]" ) {
  constexpr int n=10;
  ChessBoard empty(n);

  //codesnippet qtonetwo
  // loop over all possibilities first queen
  auto firstcol = GENERATE_COPY( range(1,n) );
  ChessBoard place_one = empty;
  REQUIRE_NOTHROW( place_one.place_next_queen_at_column(firstcol) );
  REQUIRE( place_one.feasible() );

  // loop over all possbilities second queen
  auto secondcol = GENERATE_COPY( range(1,n) );
  ChessBoard place_two = place_one;
  REQUIRE_NOTHROW( place_two.place_next_queen_at_column(secondcol) );
  if (secondcol<firstcol-1 or secondcol>firstcol+1) {
    REQUIRE( place_two.feasible() );
  } else {
    REQUIRE( not place_two.feasible() );
  }
  //codesnippet end
}

TEST_CASE( "final step","[7]" ) {
  //codesnippet qtfilllast
  ChessBoard almost( 4, {1,3,0} );
  auto solution = almost.place_queens();
  REQUIRE( solution.has_value() );
  REQUIRE( solution->filled() );
  //codesnippet end
}

//codesnippet qtfail2x2
TEST_CASE( "no 2x2 solutions","[8]" ) {
  ChessBoard two(2);
  auto solution = two.place_queens();
  REQUIRE( not solution.has_value() );
}
//codesnippet end

//codesnippet qtfail3x3
TEST_CASE( "no 3x3 solutions","[9]" ) {
  ChessBoard three(3);
  auto solution = three.place_queens();
  REQUIRE( not solution.has_value() );
}
//codesnippet end

//codesnippet qtdo4x4
TEST_CASE( "there are 4x4 solutions","[10]" ) {
  ChessBoard four(4);
  auto solution = four.place_queens();
  REQUIRE( solution.has_value() );
}
//codesnippet end
