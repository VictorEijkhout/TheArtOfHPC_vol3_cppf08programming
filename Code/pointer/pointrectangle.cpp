/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pointrectangle.cxx : skeleton code for dynrectangle
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <cmath>
using std::sqrt;

#include <vector>
using std::vector;

#include <memory>
using std::make_shared,std::shared_ptr;

class Point {
protected:
  float x,y;
public:
  Point(float ux,float uy) { x = ux; y = uy; };
  float distance(Point other) {
    float xd = x-other.x, yd = y-other.y;
    return sqrt( xd*xd + yd*yd );
  };
  void scale( float by ) { x *= by; y *= by; };
  float get_x() { return x; };
  float get_y() { return y; };
};

class DynRectangle {
private:
  Point bottom_left,top_right;
public:
  DynRectangle(Point bl,Point tr) 
    : bottom_left(bl), top_right(tr) {
  };
  float area() {
    float xsize = top_right.get_x()-bottom_left.get_x();
    float ysize = top_right.get_y()-bottom_left.get_y();
    return xsize*ysize;
  };
};

int main() {

  Point 
    origin(0,0),
    fivetwo(5,2);
  DynRectangle lielow( origin,fivetwo );

  cout << "Area: " <<  lielow.area() << '\n';

  fivetwo.scale(2);

  // scale the `fivetwo' point by two
  cout << "Area: " <<  lielow.area() << '\n';

  return 0;
}
