/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pretest.cxx : illustrating if test
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

int main() {

  //codesnippet pretest
  cout << "before the loop" << '\n';
  for (int i=5; i<4; i++)
    cout << "in iteration "
         << i << '\n';
  cout << "after the loop" << '\n';
  //codesnippet end
  return 0;
}
