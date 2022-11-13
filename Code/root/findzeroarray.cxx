/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** findzero.cxx : root finding
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <iomanip>
using std::setw;

#include <vector>
using std::vector;

#include "findzerolib.h"

int main() {

  //codesnippet rootsetcoeffcall
  vector<double> coefficients = set_coefficients();
  //codesnippet end

  //codesnippet rootoddcall
  if ( not is_odd(coefficients) ) {
    cout << "This program only works for odd-degree polynomials\n";
    exit(1);
  }
  //codesnippet end

  double left,right;
  find_initial_bounds(coefficients,left,right);

  cout << "Finding zero between " << left << " and " << right << '\n';

  //codesnippet rootfindcall
  auto zero = find_zero( coefficients, 1.e-8 );
  cout << "Found root " << zero
       << " with value " << evaluate_at(coefficients,zero) << '\n';
  //codesnippet end

  return 0;
}

