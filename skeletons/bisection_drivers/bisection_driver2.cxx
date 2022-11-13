
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

TEST_CASE( "proper test","[2]" ) {
  auto coefficients = random_coefficients(4);
  REQUIRE( proper_polynomial(coefficients) );
  coefficients.at(0) = 0.;
  REQUIRE( not proper_polynomial(coefficients) );
  vector<double> zeroset;
  REQUIRE( not proper_polynomial(zeroset) );
}
