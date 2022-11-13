/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2020-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** conststarconst.cxx : constancy and pointers
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

int main() {

  //codesnippet constptrtoint
  int i=5;
  int * const ip = &i;
  printf("ptr derefs to: %d\n",*ip);
  *ip = 6;
  printf("ptr derefs to: %d\n",*ip);
  int j;
  // DOES NOT COMPILE ip = &j;
  //codesnippet end

  //codesnippet ptrtoconstint
  const int * jp = &i;
  i = 7;
  printf("ptr derefs to: %d\n",*jp);
  // DOES NOT COMPILE *jp = 8;
  int k = 9;
  jp = &k;
  printf("ptr derefs to: %d\n",*jp);
  //codesnippet end

  //codesnippet constptrconstint
  // DOES NOT WORK const int * const kp; kp = &k;
  const int * const kp = &k;
  printf("ptr derefs to: %d\n",*kp);
  k = 10;
  // DOES NOT COMPILE *kp = 11;
  //codesnippet end

  return 0;
}
