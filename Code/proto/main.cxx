// -*- c++ -*-
/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017/9 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** main.cxx : a program file
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>

//int f(int i) { return 2*i; }
//codesnippet headeruse
#include "header.h"

int main() {
  //codesnippet end

  int i,j;
  //codesnippet headeruse
  i = 2;
  j = f(i);
  //codesnippet end
  cout << "twice " << i << " is: " << j << '\n';

  return 0;
}

  
