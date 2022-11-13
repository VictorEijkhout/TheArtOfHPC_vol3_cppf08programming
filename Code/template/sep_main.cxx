/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2021-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** sep_main.cxx : main file for explicitly instantiated template classes
 ****
 ****************************************************************/

#include "sep_head.h"

int main() {
  sep<int> s; s.f();
  sep<double> sd; sd.f();
  sep<char> sc; sc.f();
  return 0;
}
