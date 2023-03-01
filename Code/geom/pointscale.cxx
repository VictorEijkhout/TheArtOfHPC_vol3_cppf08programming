/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pointscale.cxx : Point class with private data
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <cmath>
using std::sqrt;

//codesnippet pointscale
class Point {
//codesnippet end
private:
  double x,y;
public:
  Point( double ux,double uy ) {
    x = ux; y = uy;
  };
  //codesnippet pointscale
  Point scale( double a ) {
    auto scaledpoint =
	Point( x*a, y*a );
    return scaledpoint;
  };
  //codesnippet end
  double dist_to_origin() { return sqrt(x*x + y*y); };
  Point operator*(double factor);
};
//codesnippet end

//codesnippet pointmultop
Point Point::operator*(double f) {
    return Point(f*x,f*y);
};
//codesnippet end

int main() {
  Point p1(1.,2.);
  cout << "Scale2" << '\n';
//codesnippet pointscale
  cout << "p1 to origin "
       << p1.dist_to_origin()
       << '\n';
  Point p2 = p1.scale(2.);
  cout << "p2 to origin "
       << p2.dist_to_origin()
       << '\n';
//codesnippet end
  cout << "scale2" << '\n';

  cout << "Mult2" << '\n';
//codesnippet pointmultop
  cout << "p1 to origin "
       << p1.dist_to_origin() << '\n';
  Point scale2r = p1*2.;
  cout << "scaled right: "
       << scale2r.dist_to_origin() << '\n';
  // ILLEGAL Point scale2l = 2.*p1;
//codesnippet end
  cout << "mult2" << '\n';

  return 0;
}

#if 0
//codesnippet pointscaleimpl1
Point Point::scale( double a ) {
  Point scaledpoint =
    Point( x*a, y*a );
  return scaledpoint;
};
//codesnippet end

//codesnippet pointscaleimpl2
Point Point::scale( double a ) {
  return Point( x*a, y*a );
};
//codesnippet end
#endif
