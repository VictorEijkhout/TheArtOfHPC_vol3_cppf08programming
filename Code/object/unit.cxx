/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** unit.cxx : accessor function to maintain invariant
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <sstream>
#include <cmath>

//codesnippet unitpointdef
class UnitCirclePoint {
private:
  float x,y;
public:
  UnitCirclePoint(float x) {
    setx(x); };
  void setx(float newx) {
    x = newx; y = sqrt(1-x*x);
  };
//codesnippet end
  void print() {
    cout << "(" << x << "," << y << ")" << '\n';
  };
};

int main() {
  UnitCirclePoint mypoint(.1);
  mypoint.print();
  // Illegal:
  // mypoint.x = .2
  // instead:
  mypoint.setx(.2);
  mypoint.print();

  return 0;
}
