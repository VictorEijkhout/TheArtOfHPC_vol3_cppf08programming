/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** staticbound.cxx : bound checking
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <vector>
using std::vector;

int main() {

  int numbers[5];
  numbers[5] = 3.;

  int N=7;
  int morenumbers[N];
  morenumbers[6] = -1;

  vector<float> x(5);
  x[1] = 2.;
  x[5] = -1.; // not detected!
  x.at(6) = -2.; // detected!
  
  return 0;
}
