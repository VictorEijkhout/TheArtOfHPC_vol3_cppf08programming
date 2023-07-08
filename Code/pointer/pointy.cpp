/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pointx.cxx : access through arrow
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <memory>
using std::make_shared;

class HasY {
public:
  double y;
  HasY( double y) : y(y) {};
};

int main() {
  //codesnippet pointy
  auto Y = make_shared<HasY>(5);
  cout << Y->y << '\n';
  Y.get()->y = 6;
  cout << ( *Y.get() ).y << '\n';
  //codesnippet end
}
