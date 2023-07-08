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
using std::cout, std::cin;
#include <cstdio>

int main() {

  //codesnippet if2digits
  int i;
  cin >> i;
  if ( i>100 )
    cout << "That number " << i
         << " had more than 2 digits"
         << '\n';
  //codesnippet end

  return 0;
}

