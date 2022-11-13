/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** bitor.cxx : bitwise operators
 ****
 ****************************************************************/

#include <iostream>
using std::cin,  std::cout;

int main() {
  //codesnippet bitandor
  int x=6,y=3;
  cout << "6|3 = " << (x|y) << '\n';
  cout << "6&3 = " << (x&y) << '\n';
  //codesnippet end
  return 0;
}
