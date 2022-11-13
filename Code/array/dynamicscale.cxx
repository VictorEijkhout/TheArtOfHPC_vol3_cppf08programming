/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** dynamicscale.cxx : static array length examples
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int main() {

  //examplesnippet dynamicscale
  vector<int> numbers = {1,4,2,6,5};
  for ( auto &v : numbers )
    v *= 3;
  cout << "Scale 0'th by 3: " << numbers[0] << '\n';
  //examplesnippet end
    
  return 0;
}
