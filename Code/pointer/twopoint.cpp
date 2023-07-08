/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pointx.cxx : access through arrow
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <memory>
using std::make_shared;

//codesnippet hasxdef
class HasX {
private:
  double x;
public:
  HasX( double x) : x(x) {};
  auto get() { return x; };
  void set(double xx) { x = xx; };
};
//codesnippet end

int main() {

  //codesnippet twopoint
  auto xptr = make_shared<HasX>(5);
  auto yptr = xptr;
  cout << xptr->get() << '\n';
  yptr->set(6);
  cout << xptr->get() << '\n';
  //codesnippet end

  return 0;
}
