/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** shortvector.cxx : first example of simple vectors
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//codesnippet shortvectorex
#include <vector>
using std::vector;

int main() {
  vector<int> evens{0,2,4,6,8};
  vector<float> halves = {0.5, 1.5, 2.5};
  auto halfloats = {0.5f, 1.5f, 2.5f};
  cout << evens.at(0) << '\n';
  return 0;
}
//codesnippet end
