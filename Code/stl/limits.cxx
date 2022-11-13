/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016=2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** limits.cxx : illustration of numeric limits
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <limits>
using std::numeric_limits;

int main() {
  int lasttest;

  cout << "Limit" << '\n';
  //codesnippet stllimits
  cout << "Signed int: "
       << numeric_limits<int>::min() << " "
       << numeric_limits<int>::max()
       << '\n';
  cout << "Unsigned    "
       << numeric_limits<unsigned int>::min() << " "
       << numeric_limits<unsigned int>::max()
       << '\n';
  cout << "Single      "
       << numeric_limits<float>::denorm_min() << " "
       << numeric_limits<float>::min() << " "
       << numeric_limits<float>::max()
       << '\n';
  cout << "Double      "
       << numeric_limits<double>::denorm_min() << " "
       << numeric_limits<double>::min() << " "
       << numeric_limits<double>::max()
       << '\n';
  //codesnippet end
  cout << ".. limit" << '\n';

  cout << "Macheps" << '\n';
  //codesnippet stllimitfloat
  cout << "Single lowest "
       << numeric_limits<float>::lowest()
       << " and epsilon "
       << numeric_limits<float>::epsilon()
       << '\n';
  cout << "Double lowest "
       << numeric_limits<double>::lowest()
       << " and epsilon "
       << numeric_limits<double>::epsilon()
       << '\n';
  //codesnippet end
  cout << ".. macheps" << '\n';

  return 0;
}
