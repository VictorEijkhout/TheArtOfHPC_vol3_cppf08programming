/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** vectorrangecopy.cxx : range-based indexing over a vector
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int main() {

  //codesnippet vectorrangecopy
  vector<float> myvector
    = {1.1, 2.2, 3.3};
  for ( auto e : myvector )
    e *= 2;
  cout << myvector.at(2) << '\n';
  //codesnippet end

  return 0;
}
