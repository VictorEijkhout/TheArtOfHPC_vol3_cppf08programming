/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** iter.cxx : tinkering with iterators
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

#include <cassert>

int main() {

  vector<float> v{1.5f, 2.5f};
  for ( vector<float>::iterator e=v.begin(); e!=v.end(); ++e )
    cout << *e << '\n';

  return 0;
}
