/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016=2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** round.cxx : rounding behavior
 ****
 ****************************************************************/

#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
using namespace std;

#include <cfenv>

int main() {

  float f_point7;
  double d_point7;
  cin >> f_point7;
  cin >> d_point7;

  vector<int> roundings = {FE_TONEAREST, FE_UPWARD, FE_DOWNWARD, FE_TOWARDZERO};
  for ( auto round : roundings ) {
    fesetround(round);
    double d_one7, d_zero7 = 0.7;
    d_one7 = 1. + d_point7; d_zero7 = 0. + d_point7;

    float f_one7, f_zero7;
    f_one7 = 1.f + f_point7; f_zero7 = 0.f + f_point7;

    cout
      << boolalpha << ( f_one7<d_one7 )
      << " "
      << boolalpha << ( f_zero7<d_zero7 )
      << '\n';
  }

  return 0;
}
