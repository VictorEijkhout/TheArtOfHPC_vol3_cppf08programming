/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-9 Victor Eijkhout eijkhout@tacc.utexas.edu
 ***
 **** dynamicmax.cxx : static array length examples
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int main() {

  //examplesnippet dynamicmax
  vector<int> numbers = {1,4,2,6,5};
  int tmp_max = -2000000000;
  for (auto v : numbers)
    if (v>tmp_max)
      tmp_max = v;
  cout << "Max: " << tmp_max
       << " (should be 6)" << '\n';
  //examplesnippet end
    
  return 0;
}
