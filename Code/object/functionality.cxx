/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-9 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** functionality.cxx : illustrating object functionality
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <cmath>
using std::sqrt;

//codesnippet functionalityconstruct
class Point {
private: // members
  double x,y;
public: // methods, first the constructor:
  Point
    ( double in_x,double in_y )
    : x(in_x),y(in_y) {};
  //codesnippet end
  //codesnippet stationalitymethod
  void scaleby( double a ) {
    x *= a; y *= a; };
  //codesnippet end
  //codesnippet functionalitymethod
  double distance_to_origin() {
    return sqrt(x*x + y*y); };
  //codesnippet end
  double angle() {
    return atan2(y,x);
  };
//codesnippet functionalityconstruct
};
//codesnippet end

int main() {
  {
    //codesnippet constructoruse
    Point v(1.,2.);
    //codesnippet end
  }

  //codesnippet functionality
  Point p(1.,2.); // make point (1,2)
  cout << "distance to origin "
       << p.distance_to_origin() << '\n';
  p.scaleby(2.);
  cout << "distance to origin "
       << p.distance_to_origin() << '\n'
       << "and angle " << p.angle()
       << '\n';
  //codesnippet end

  //codesnippet functionalitymethoduse
  Point pt(5,12);
  double
    s = pt.distance_to_origin();
  //codesnippet end
  double
    a = pt.angle();

  return 0;
}

#if 0
//codesnippet functionalityconstructconstruct
class Point {
private: // members
  double x,y;
public: // methods
  Point( double in_x,double in_y ) {
    x = in_x; y = in_y;
  };
};
//codesnippet end
//codesnippet functionalityconstructmyx
class Point {
private: // members
  double x,y;
public: // methods
  Point( double x,double y )
    : x(x),y(y) {};
};
//codesnippet end
#endif
