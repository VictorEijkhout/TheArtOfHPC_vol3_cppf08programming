/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** arrayaddr.cxx : pointer to C style array
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

int main() {

  //codesnippet arrayaddr
  double array[5] = {11,22,33,44,55};
  double *addr_of_second = &(array[1]);
  cout << *addr_of_second << '\n';
  array[1] = 7.77;
  cout << *addr_of_second << '\n';
  //codesnippet end

  return 0;
}
