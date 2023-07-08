/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** intprec.cxx : test precision of int types
 ****
 ****************************************************************/

#include <cmath>
using std::abs;

#include <iostream>
using std::cout;
#include <iomanip>
using std::boolalpha;

int main() {

  //codesnippet intshortlong
  short int ishort = 1024;
  short ishort2;
  int normal = 2000111222;
  long int much = 1234567890123;
  long much2;
  long long int whole_lot;
  long long whole_lot2;
  //codesnippet end

  return 0;
}

