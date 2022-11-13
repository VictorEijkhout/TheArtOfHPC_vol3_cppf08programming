/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ***
 **** rangemax.cxx : static array length examples
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int main() {

  //examplesnippet rangemax
  int numbers[] = {1,4,2,6,5};
  int tmp_max = numbers[0];
  for (auto v : numbers)
    if (v>tmp_max)
      tmp_max = v;
  cout << "Max: " << tmp_max << " (should be 6)" << '\n';
  //examplesnippet end
    
  return 0;
}
