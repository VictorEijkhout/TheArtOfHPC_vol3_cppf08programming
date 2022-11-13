/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** gridpoint.cxx : point with integer coordinates
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct GridPoint {
  int x; int y;
};

int main() {

  struct GridPoint p1;
  p1.x = 1.; p1.y = 2.;

  cout << "The Manhattan distance is: "
       << p1.x+p1.y
       << endl;
  
  return 0;
}

