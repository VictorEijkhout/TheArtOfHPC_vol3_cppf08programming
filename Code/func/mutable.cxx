/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** lambdacapture.cxx : exploring the capture
 ****
 ****************************************************************/

#include <functional>
using std::function;

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <string>
using std::string;
using std::to_string;

int main() {

  {
    cout << "NonMutable\n";
    //codesnippet lambdanonmutable
    float x = 2, y = 3;
    auto f = [x] ( float &y ) -> void {
      int xx = x*2; y += xx; };
    f(y);
    cout << y << '\n';
    f(y);
    cout << y << '\n';
    //codesnippet end
    cout << "nonmutable\n";
  }
  
  {
    cout << "YesMutable\n";
    //codesnippet lambdayesmutable
    float x = 2, y = 3;
    auto f = [x] ( float &y ) mutable -> void {
      x *= 2; y += x; };
    f(y);
    cout << y << '\n';
    f(y);
    cout << y << '\n';
    //codesnippet end
    cout << "yesmutable\n";
  }
  
  return 0;
}
