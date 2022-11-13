/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** range.cxx : range-based iteration over a class
 ****
 ****************************************************************/

#include <iostream>
using std::boolalpha;
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>
using std::any_of;

int main() {

  cout << "ANY.." << '\n';
  //codesnippet rangeany
  vector<int> integers{1,2,3,5,7,10};
  auto any_even = any_of
    ( integers.begin(),integers.end(),
      [=] (int i) -> bool {
        return i%2==0; }
      );
  if (any_even)
    cout << "there was an even" << '\n';
  else
    cout << "none were even" << '\n';
  //codesnippet end
  cout << "..any" << '\n';

  return 0;
}
