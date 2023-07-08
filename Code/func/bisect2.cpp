/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** bisect2.cxx : example of introducing functions
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

//codesnippet bisect2func
float f(float x) {
  return x*x*x - x*x-1;
};
//codesnippet end

int main() {
  float left{0.},right{2.},
    mid;
  //codesnippet bisect2main
  while (right-left>.1) {
    mid = (left+right)/2.;
    float fmid = f(mid);
    if (fmid<0)
      left = mid;
    else
      right = mid;  
  }
  //codesnippet end
  cout << "Zero happens at: " << mid << '\n';
}
