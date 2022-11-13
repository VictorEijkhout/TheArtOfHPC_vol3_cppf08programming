/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** set.cxx : make a Set class, containing points
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <cmath>
using std::sqrt;

#include <vector>
using std::vector;

//codesnippet setminusset
class Point {
private:
  float x,y;
public:
  Point(float ux,float uy) { x = ux; y = uy; };
  // other methods omitted
};
//codesnippet end

//codesnippet pointset
class Set {
private:
  vector<Point> points;
public:
  Set() {};
  void add( Point p ) {
    points.push_back(p);
  };
  int cardinality() {
    return points.size();
  };
};
//codesnippet end

//codesnippet setminusset
int main() {
  Set set;

  set.add( Point(1.0,1.0) );
  set.add( Point(2.0,2.0) );
  cout << "Number of points: " << set.cardinality() << '\n';
  
  Point p3(4.0,5.0);
  set.add( p3 );
  cout << "Number of points: " << set.cardinality() << '\n';

  return 0;
}
//codesnippet end
