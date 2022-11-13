/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** ref.cxx : using references, not as parameter
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

int main() {

  //codesnippet refint
  int i;
  int &ri = i;
  i = 5;
  cout << i << "," << ri << '\n';
  i *= 2;
  cout << i << "," << ri << '\n';
  ri -= 3;
  cout << i << "," << ri << '\n';
  //codesnippet end

  return 0;
}
