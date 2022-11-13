/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** ijloop.cxx : double loop over ij
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main() {

  for (int i=0; i<10; i++) {
    for (int j=0; j<10; j++) {
      cout << "(" << i << "," << j << ") ";
    }
  }

  return 0;
}
