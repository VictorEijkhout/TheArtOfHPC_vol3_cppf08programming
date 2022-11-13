/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pointconststruct.cxx : Vector class with constructor
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//codesnippet pointconstruct
class Vector {
private:
  double vx,vy;
public:
  // constructor
  Vector( double userx,double usery ) {
    vx = userx; vy = usery;
  }
  //codesnippet end
  //codesnippet pointaccess
  // accessors
  double x() { return vx; };
  double y() { return vy; };
  //codesnippet end
};

int main() {
//codesnippet pointconstructuse
  Vector p1(1.,2.), p2(3.7,-21./5);
//codesnippet end
  cout << "p1 = " << p1.x() << "," << p1.y() << '\n';

  return 0;
}
