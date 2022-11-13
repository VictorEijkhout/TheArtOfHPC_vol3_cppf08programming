/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** if.cxx : very simple conditional example
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <cstdio>

int main() {

  //snippet if2digits
  int i;
  cin >> i;
  if ( i>100 )
    cout << "That number " << i << " had more than 2 digits" << endl;
  //snippet end

  return 0;
}

