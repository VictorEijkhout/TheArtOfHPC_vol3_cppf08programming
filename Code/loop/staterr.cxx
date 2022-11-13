/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** staterr.cxx : indexing error, statically detectable
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

int main() {

  //codesnippet staterr
  int a[5];
  a[6] = 1.;
  //codesnippet end

  return 0;
}
