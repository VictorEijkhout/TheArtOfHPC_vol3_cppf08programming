/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pointaggregate.cxx : aggregate construction
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
  double x() { return vx; };
  double y() { return vy; };
};

int main() {

  Vector p1( {1.,2.} ), p2( {3.7,-21./5} );

  cout << "p1 = " << p1.x() << "," << p1.y() << '\n';

  return 0;
}
