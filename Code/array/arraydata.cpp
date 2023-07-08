/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** arraydata.cxx : exploring the data of a vector
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <cstdio>

int main() {

  vector<int> ar(5,2);

  int
    *addr_data  = ar.data(),
    *addr_first = &(ar[0]),
    *addr_at0   = &ar.at(0);
  printf("data: %ld [0]: %ld at(0): %ld\n",
	 (long)addr_data,(long)addr_first,(long)addr_at0);
  
  return 0;
}
