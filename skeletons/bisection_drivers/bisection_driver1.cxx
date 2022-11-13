
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

TEST_CASE( "coefficients are polynomial","[1]" ) {
  auto coefficients = random_coefficients(3);
  REQUIRE( coefficients.size()>0 );
  REQUIRE( coefficients.front()!=0. );
}
