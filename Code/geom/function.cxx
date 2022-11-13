/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** function.cxx : Function class with slope & intercept
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <cmath>
using std::sqrt;

class Point {
private:
  float stored_x,stored_y;
public:
  Point() {};
  Point(float ux,float uy) { stored_x = ux; stored_y = uy; };
  float distance(Point other) {
    float xd = stored_x-other.x(), yd = stored_y-other.y();
    return sqrt( xd*xd + yd*yd );
  };
  float x() { return stored_x; };
  float y() { return stored_y; };
};

class LinearFunction {
private:
  Point p1,p2;
  float stored_slope,stored_intercept;
public:
  LinearFunction( Point p1,Point p2 ) {
    this->p1 = p1; this->p2 = p2;
    stored_slope = ( p2.y() - p1.y() ) / ( p2.x() - p1.x() );
    stored_intercept  = ( p2.x()*p1.y() - p1.x()*p2.y() ) / ( p2.x()-p1.x() );
  }
  float slope() { return stored_slope; };
  float intercept() { return stored_intercept; };
};


int main() {

  Point p1(1.0,2.0), p2(2.0,3.0);
  LinearFunction line(p1,p2);
  cout << "Line has slope " << line.slope() << '\n';
  cout << "Line has intercept " << line.intercept() << '\n';
  
  return 0;
}
