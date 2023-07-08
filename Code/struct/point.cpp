/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-9 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** point.cxx : struct for cartesian vector
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//codesnippet structdef
struct Point {
  double x; double y; int label;
};
//codesnippet end

//codesnippet structuse
int main() {

  struct Point p1,p2;

  p1.x = 1.; p1.y = 2.; p1.label = 5;
  p2 = {3.,4.,5};

  p2 = p1;
  cout << "p2: "
       << p2.x << "," << p2.y
       << '\n';
  //codesnippet end
  
  return 0;
}

