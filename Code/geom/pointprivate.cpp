/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pointprivate.cxx : Vector class with private data
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//codesnippet pointprivate
class Vector {
private: // recommended!
  double vx,vy;
public:
  Vector( double x,double y ) {
    vx = x; vy = y;
  };
  //codesnippet end
  //codesnippet pointprivateset
public:
  double x() { return vx; };
  double y() { return vy; };
  void setx( double newx ) {
    vx = newx; };
  void sety( double newy ) {
    vy = newy; };
  //codesnippet end
  //codesnippet pointprivateclose
}; // end of class definition
//codesnippet end

int main() {
  //codesnippet pointprivatedefine
  Vector p1(1.,2.);
  //codesnippet end
  cout << "p1 = " << p1.x() << "," << p1.y() << '\n';

  //codesnippet pointprivatesetuse
  p1.setx(3.12);
  /* ILLEGAL: p1.x() = 5; */
  cout << "P1's x=" << p1.x() << '\n';
  //codesnippet end

  return 0;
}
