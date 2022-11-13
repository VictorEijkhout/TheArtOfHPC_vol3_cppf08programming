/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pointconststruct.cxx : Vector class with constructor
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout, std::ostream;
#include <iomanip>
using std::boolalpha;

class Point {
private:
  double vx,vy;
public:
  Point( double userx,double usery ) {
    vx = userx; vy = usery;
  }
  //codesnippet spaceshipless
  bool operator<( const Point& two ) const {
    if (vx!=two.vx)
      return vx<two.vx;
    else return vy<two.vy;
  }
  auto operator<=>( const Point& other ) const = default;
  //codesnippet end
  friend ostream& operator<<( ostream& s,const Point& p ) {
    s << "(" << p.vx << "," << p.vy << ") ";
    return s;
  };
};


int main() {

  Point p1(1.,2.), p2(1.,3.), p3(3.,1.);

  for ( const auto& x1 : { p1,p2,p3} )
    for ( const auto& x2 : { p1,p2,p3 } )
      cout << x1 << " <=> " << x2 << ": "
	   << boolalpha << (x1<x2) << " "
	   << boolalpha << (x1==x2) << " "
	   << boolalpha << (x1>x2) << " "
	   << '\n';

  return 0;
}
