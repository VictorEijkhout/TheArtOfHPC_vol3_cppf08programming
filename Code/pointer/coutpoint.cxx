/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-9 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** coutpoint.cxx : print a pointer
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

int main() {

  //codesnippet coutpoint
  int i;
  cout << "address of i, decimal: "
       << (long)&i << '\n';
  cout << "address of i, hex    : "
       << std::hex << &i << '\n';
  //codesnippet end

  return 0;
}
