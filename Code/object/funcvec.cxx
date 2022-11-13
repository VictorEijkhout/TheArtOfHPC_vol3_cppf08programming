/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** funcvec.cxx : implementing a functional vector on virtual vector base
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <vector>
using std::vector;

#include "virtualvec.h"

//codesnippet virtvecfunc
class FuncVector : VirtualVector {
private:
  int size{-1};
  float basevalue{0.};
  bool linear{false};
public:
  FuncVector( int s ) {
    size = s;
  };
  void setlinear( float v ) {
    linear = true; basevalue = v;
  };
  float operator[](int i) {
    if (i<0 || i>=size)
      throw(1);
    else if (!linear)
      throw(2);
    else
      return i*basevalue;
  };
};
//codesnippet end

int main() {
  FuncVector v(5);
  v.setlinear(7.2);
  cout << v[3] << '\n';
  return 0;
}
