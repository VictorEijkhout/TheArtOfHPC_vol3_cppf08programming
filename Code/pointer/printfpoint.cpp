/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** printfpoint.cxx : print a pointer
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

int main() {

  //codesnippet printfpoint
  int i;
  printf("address of i: %ld\n",
         (long)(&i));
  printf(" same in hex: %lx\n",
         (long)(&i));
  //codesnippet end

  return 0;
}
