/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** constperf.cxx : try to show compiler optimization from const
 **** DOES NOT WORK
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include "constperf.h"

int main() {
  
  c myobj;
  double tot{0.};
  for (int i=0; i<200000000; i++) {
    auto f = myobj.f();
    tot += myobj.f();
  }
  cout << tot << '\n';
  
  return 0;
}
