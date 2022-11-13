/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** nan.cxx : NaN behavior
 ****
 ****************************************************************/

#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>
using namespace std;

int main() {

  //codesnippet nanhasnan
  cout << "Double NaNs: "
       << std::numeric_limits<double>::quiet_NaN()     << ' ' // nan
       << std::numeric_limits<double>::signaling_NaN() << ' ' // nan
       << '\n'
       << "zero divided by zero: "
       << 0 / 0.0         << '\n';
  cout << boolalpha
       << "Int has NaN: "
       << std::numeric_limits<int>::has_quiet_NaN
       << '\n';
  //codesnippet end

  return 0;
}
