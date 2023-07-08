/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-9 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** bisect1.cxx : example of a code without functions
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int main() {
  //codesnippet bisect1main
  float left{0.},right{2.},
    mid;
  while (right-left>.1) {
    mid = (left+right)/2.;
    float fmid =
      mid*mid*mid - mid*mid-1;
    if (fmid<0)
      left = mid;
    else
      right = mid;  
  }
  cout << "Zero happens at: " << mid << '\n';
  //codesnippet end
}
