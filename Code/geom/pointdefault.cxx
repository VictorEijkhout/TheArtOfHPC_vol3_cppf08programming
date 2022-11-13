/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-9 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pointscale.cxx : Point class with private data
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <cmath>
using std::sqrt;

class Point {
private:
  double x,y;
public:
//codesnippet pointdef1
  Point() {};
  Point( double x,double y )
    : x(x),y(y) {};
//codesnippet end
  Point scale( double a ) {
    return Point( x*a, y*a ); };
  double length() { return sqrt(x*x + y*y); };
};

int main() {
//codesnippet pointdef2
  Point p1(1.,2.), p2;
  cout << "p1 to origin " << p1.length() << '\n';
  p2 = p1.scale(2.);
  cout << "p2 to origin " << p2.length() << '\n';
//codesnippet end

  return 0;
}
