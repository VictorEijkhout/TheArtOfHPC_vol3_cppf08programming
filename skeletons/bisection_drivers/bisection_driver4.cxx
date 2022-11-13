
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

TEST_CASE( "polynomial evaluation","[4]" ) {
  // correct interpretation: 2x^2 + 1
  vector<double> second{2,0,1}; 
  REQUIRE( proper_polynomial(second) );
  REQUIRE( evaluate_at(second,2) == Catch::Approx(9) );
  // wrong interpretation: 1x^2 + 2
  REQUIRE( evaluate_at(second,2) != Catch::Approx(6) );
  REQUIRE( evaluate_at(second,2) == Catch::Approx(9) );
  vector<double> third{3,2,0,1}; // 3x^3 + 2x^2 + 1
  REQUIRE( proper_polynomial(third) );
  REQUIRE( evaluate_at(third,0) == Catch::Approx(1) );
}
