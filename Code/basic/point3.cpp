/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** point3.cxx : about truncation to float
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

int main() {

  //codesnippet truncvsf
  double point3d = .3/.7;
  float
    point3f = .3f/.7f,
    point3t = point3d;
  cout << "double precision: "
       << point3d << '\n'
       << "single precision: "
       << point3f << '\n'
       << "difference with truncation:"
       << point3t - point3f
       << '\n';
  //codesnippet end
  
  return 0;
}
