/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** enum.cxx : examples of enums
 ****
 ****************************************************************/

#include <iostream>
using namespace std;

int main() {
  
  enum colors { red,blue,green };
  cout << red << "," << blue << "," << green << '\n';

  return 0;
}
