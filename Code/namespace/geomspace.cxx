/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** geomspace.cxx : geometry code in name space
 ****
 ****************************************************************/

#include <cmath>
#include <iostream>
#include <vector>

namespace geometry {
  class point {
  private:
    double xcoord,ycoord;
  public:
    point() {};
    point( double x,double y ) {
      xcoord = x; ycoord = y; };
    double x() { return xcoord; }; // `accessor'
    double y() { return ycoord; };
  };
  class vector {
  private:
    point from,to;
  public:
    vector( point from,point to) {
      this->from = from; this->to = to;
    };
    double size() {
      double
	dx = to.x()-from.x(), dy = to.y()-from.y();
      return sqrt( dx*dx + dy*dy );
    };
  };
}
using namespace geometry;

int main() {


  std::vector< geometry::vector > vectors;
  vectors.push_back( vector( point(1,1),point(4,5) ) );
  std::cout << "and the first has length " << vectors[0].size() << '\n';

  return 0;
}
