
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <iomanip>
using std::setw;

#include <vector>
using std::vector;

#include "YOUR FILE HERE"

#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

/*
 * Auxiliary routine 
 * for creating polynomial coefficients
 */
vector<double> random_coefficients(int degree) {
  vector<double> coefficients(degree+1);
  for (int c=0; c<=degree; c++) {
      coefficients.at(c) = -4.5 + rand() % 10 ;
  }
  return coefficients;
};

TEST_CASE( "outer bounds","[5]" ) {
  double left{10},right{11};
  right = left+1;
  vector<double> second{2,0,1}; // 2x^2 + 1
  REQUIRE_THROWS( find_outer(second,left,right) );
  vector<double> third{3,2,0,1}; // 3x^3 + 2x^2 + 1
  REQUIRE_NOTHROW( find_outer(third,left,right) );
  REQUIRE( left<right );
  double
    leftval = evaluate_at(third,left),
    rightval = evaluate_at(third,right);
  REQUIRE( leftval*rightval<=0 );
}
