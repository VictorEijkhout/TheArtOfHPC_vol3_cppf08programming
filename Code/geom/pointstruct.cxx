/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-9 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pointstruct.cxx : make a Point class look just like a struct
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//codesnippet pointstruct
class Vector {
public:
  double x,y;
};

int main() {
  Vector p1;
  p1.x = 1.; // This Is Not A Good Idea. See later.
  p1.y = 2.; // same
  cout << "sum of components: "
       << p1.x+p1.y  << '\n';
//codesnippet end

  return 0;
}
