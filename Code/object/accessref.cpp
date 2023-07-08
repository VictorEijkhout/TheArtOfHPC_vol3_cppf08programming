/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** accessref.cxx : method returning reference
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

//codesnippet objaccessref
class SomeObject {
private:
  float x=0.;
public:
  SomeObject( float v ) : x(v) {};
  float &xvalue() { return x; };
};

int main() {
  SomeObject myobject(1.);
  cout << "Object member initially :"
       << myobject.xvalue() << '\n';
  myobject.xvalue() = 3.;
  cout << "Object member updated   :"
       << myobject.xvalue() << '\n';
  //codesnippet end

  return 0;
}
