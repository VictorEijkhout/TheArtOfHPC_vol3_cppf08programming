/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** arraysize.cxx : size of C arrays
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

int main() {

  float values[] = {1.1, 2.2, 3.3};
  cout << values.size() << '\n';

  return 0;
}
