/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** ed.cxx : precision stuff
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

int main() {
  //codesnippet helloc
  double e1 = .1f;
  double d1 = .1;
  cout << e1 << '\n';
  cout << d1 << '\n';
  cout << e1-d1 << '\n';
  //codesnippet end
  return 0;
}
