/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** fgmain.cxx : simple module program
 ****
 ****************************************************************/

#include <iostream>

//codesnippet mainwithmod
import fg_module;
int main() {
  std::cout << "Hello world " << f(5) << '\n';
  //codesnippet end
  return 0;
}
