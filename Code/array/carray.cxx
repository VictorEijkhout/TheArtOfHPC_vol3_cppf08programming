/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** carray.cxx : arrays and malloc stuff in C
 ****
 ****************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;

//codesnippet sizeofpassedx
void std_f( int stat[] ) {
  printf(".. in function: %lu\n",std::size(stat));
}
//codesnippet  end

int main() {

  printf("Statprint\n");
  //codesnippet sizeofpassedx
  int stat[23];
  std_f( stat );
  //codesnippet end
  printf("statprint\n");

  return 0;
}
