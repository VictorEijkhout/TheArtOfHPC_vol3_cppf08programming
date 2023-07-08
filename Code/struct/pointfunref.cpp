/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pointfunref.cxx : passing structure by ref
 ****
 ****************************************************************/

#include <cmath>

#include <iostream>
using std::cin;
using std::cout;

struct point { double x; double y; } ;

//codesnippet structpassref
double distance( const struct point &p1,const struct point &p2 ) {
  double d1 = p1.x-p2.x, d2 = p1.y-p2.y;
  return sqrt( d1*d1 + d2*d2 );
}
//codesnippet end

int main() {

  struct point p1,p2;

  p1.x = 1.; p1.y = 1.;
  p2.x = 4.; p2.y = 5.;

  cout << "Distance: " << distance(p1,p2) << '\n';
  
  return 0;
}

