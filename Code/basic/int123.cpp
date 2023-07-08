/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** intprec.cxx : test precision of int types
 ****
 ****************************************************************/

#include <cmath>
using std::abs;

#include <iostream>
using std::cin, std::cout;
#include <iomanip>
using std::boolalpha;

#include <vector>
using std::vector;

#include "printbits.cpp"
#include <cfenv>

int main() {

  float pointone; cin >> pointone;
  vector<int> roundings = {FE_TONEAREST, FE_UPWARD, FE_DOWNWARD, FE_TOWARDZERO};
  for ( auto round : roundings ) {
    fesetround(round);
    float sum = pointone+0.2f, three = 0.3f;
    cout << boolalpha << (sum==three) << '\n';
    cout << sum-three << '\n';
  }

  return 0;
}

