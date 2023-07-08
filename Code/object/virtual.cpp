/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** virtual.cxx : virtual methods and overriding
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <sstream>
#include <cmath>

//codesnippet virtualoverride
class Base {
protected:
  int i;
public:
  Base(int i) : i(i) {};
  virtual int value() { return i; };
};

class Deriv : public Base {
public:
  Deriv(int i) : Base(i) {};
  virtual int value() override {
    int ivalue = Base::value();
    return ivalue*ivalue;
  };
};
//codesnippet end

int main() {

  Deriv five(5);
  cout << five.value() << '\n';
  return 0;
}
