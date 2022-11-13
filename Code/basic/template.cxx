/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** template.cxx : example of template use
 ****
 ****************************************************************/


template< typename scalar >
scalar square(scalar n) {
  return n*n;
};

#include <iostream>
using std::cout;

int main() {

  cout << "Real: " << square(2.0) << '\n';
  cout << "Integer: " << square(2) << '\n';

  return 0;
}

