/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** rvaluecopy.cxx : non-working illustration of rvalue references
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include "rvaluecopyhead.hpp"

integer::integer( int i ) : data(i) {
  std::cout << "construct " << i << '\n';
};

integer::integer( const integer &i ) {
  data = i.data;
  std::cout << "copy!" << '\n';
};

integer::integer( const integer &&i ) {
  data = i.data;
  std::cout << "ccopy!" << '\n';
};

integer integer::operator+( const integer &i ) {
  return integer(data+i.data);
};

