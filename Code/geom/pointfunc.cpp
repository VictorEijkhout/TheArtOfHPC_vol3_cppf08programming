/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pointfun.cxx : class with method
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//codesnippet pointfuncout
#include <sstream>
using std::stringstream;
#include <string>
using std::string;
//codesnippet end

#include <cmath>
using std::sqrt;

//codesnippet pointfunc
class Point {
private:
  double x,y;
public:
  Point( double xx,double yy )
    : x(xx),y(yy) {};
  double length() {
    return sqrt(x*x + y*y); };
  //codesnippet end
  //codesnippet pointangle
  double angle() {
    return 0.; /* something trig */;
  };
  //codesnippet end
  //codesnippet pointfuncout1
  string as_string() {
    stringstream ss;
    ss << "(" << x << "," << y << ")";
    return ss.str();
  };
  //codesnippet end
};

//codesnippet pointfuncout1
std::ostream& operator<<
(std::ostream &out,Point &p) {
  out << p.as_string(); return out;
};
//codesnippet end

int main() {
  cout << "Simple\n";
  {
    //codesnippet pointfunc
    Point p1(1.,2.);
    cout << "p1 has length "
         << p1.length() << "\n";
    //codesnippet end
  }
  cout << "simple\n";
  
  cout << "Cout\n";
  {
    //codesnippet pointfuncout2
    Point p1(1.,2.);
    cout << "p1 " << p1
         << " has length "
         << p1.length() << "\n";
    //codesnippet end
  }
  cout << "cout\n";

  return 0;
}
