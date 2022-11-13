/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pointx.cxx : access through arrow
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

//codesnippet pointxuse
#include <memory>
using std::make_shared;

//codesnippet end

//codesnippet pointx
class HasX {
private:
  double x;
public:
  HasX( double x) : x(x) {};
  auto value() { return x; };
  void set(double xx) { x = xx; };
};
//codesnippet end

int main() {

  //codesnippet pointxuse
  HasX xobj(5);
  cout << xobj.value() << '\n';
  xobj.set(6);
  cout << xobj.value() << '\n';

  auto xptr = make_shared<HasX>(5);
  cout << xptr->value() << '\n';
  xptr->set(6);
  cout << xptr->value() << '\n';
  //codesnippet end

  return 0;
}
