/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** bisect3.cxx : example of a bisection code with functions introduced
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

//codesnippet bisect3func
float f(float x) {
  return x*x*x - x*x-1;
};
float find_zero_between
    (float l,float r) {
  float mid;
  while (r-l>.1) {
    mid = (l+r)/2.;
    float fmid = f(mid);
    if (fmid<0)
      l = mid;
    else
      r = mid;  
  }
  return mid;
};
//codesnippet end

//codesnippet bisect3main
int main() {
  float left{0.},right{2.};
  float zero =
    find_zero_between(left,right);
  cout << "Zero happens at: "
       << zero << '\n';
  return 0;
}
  //codesnippet end
