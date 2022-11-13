/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** hellopi.cxx : your basic hello world with computation
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <cmath>

int main() {
  cout << "Hello world: " << 4*atan(1.e0) << '\n';
  return 0;
}
