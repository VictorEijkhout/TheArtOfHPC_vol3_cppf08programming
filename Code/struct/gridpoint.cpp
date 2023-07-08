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

//codesnippet structdefgrid
struct GridPoint {
  int x; int y;
};
//codesnippet end

int main() {

//codesnippet structusegrid
  struct GridPoint p1;
  p1.x = 1.; p1.y = 2.;

  cout << "The Manhattan distance is: "
       << p1.x+p1.y
       << '\n';
  //codesnippet end
  
  return 0;
}

