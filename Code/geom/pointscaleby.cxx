/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pointscaleby.cxx : method that operates on members
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <cmath>
using std::sqrt;

//codesnippet pointscaleby
class Point {
//codesnippet end
private:
  double x,y;
public:
  Point( double xx,double yy ) {
    x = xx; y = yy;
  };
//codesnippet pointscaleby
  void scaleby( double a ) {
    x *= a; y *= a; };
//codesnippet end
  double length() {
    return sqrt(x*x + y*y); };
//codesnippet pointscaleby
};
//codesnippet end

int main() {
//codesnippet pointscaleby
  Point p1(1.,2.);
  cout << "p1 to origin "
       << p1.length() << '\n';
  p1.scaleby(2.);
  cout << "p1 to origin "
       << p1.length() << '\n';
//codesnippet end

  return 0;
}
