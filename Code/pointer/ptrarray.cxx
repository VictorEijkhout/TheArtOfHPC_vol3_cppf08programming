/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** ptrarray.cxx : pointer to C style array
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <memory>
using std::shared_ptr;
using std::make_shared;

int main() {

  //codesnippet ptrarray
  auto array = make_shared<double>(50);
  // shared_ptr<double> other;
  // other = array;
  // cout << other.get()[2] << '\n';
  //codesnippet end

  return 0;
}
