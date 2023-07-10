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

int main() {

  //codesnippet vecdist
  vector<int> numbers{1,3,5,7,9};
  auto it=numbers.begin();
  while ( it!=numbers.end() ) {
    auto d = distance(numbers.begin(),it);
    cout << "At distance " << d
         << ": " << *it << '\n';
    ++it;
  }
  //codesnippet end

  return 0;
}
