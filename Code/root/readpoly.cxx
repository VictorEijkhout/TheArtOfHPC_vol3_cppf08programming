/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** readpoly.cxx : enter polynomials coefficients
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include "poly.h"

int main() {

  polynomial poly;

  double f100 = poly.evaluate_at(100);
  double f0 = poly.evaluate_at(0.);
  double fm100 = poly.evaluate_at(-100);

  cout << "Values at -100: " << fm100 << ", 0: " << f0 << ", +100: " << f100 << '\n';
  
  return 0;
}

