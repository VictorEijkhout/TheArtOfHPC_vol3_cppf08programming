/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pyth.cxx : pythagoras triples
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <cmath>

int main() {

  for (int x=0; x<=5; ++x) {
    double x11 = pow(11,x);
    long   i11 = pow(11,x);
    cout << x11 << " " << i11 << '\n';
  }
  
  return 0;
}
