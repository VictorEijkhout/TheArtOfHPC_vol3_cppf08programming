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

// is there a way to optimize the at function?

//int vector<int>::operator [](int i) { return this->at(i); };

template<>
int &vector<int>::at(int i) { return (*this)[i]; };

int main() {

  //examplesnippet rangeout
  vector<int> numbers = {1,4,2,6,5};
  numbers[7] = 8;
  //examplesnippet end
    
  return 0;
}
