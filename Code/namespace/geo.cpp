/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** geo.cxx : geometry code in name space, using lib and header file
 ****
 ****************************************************************/

#include <iostream>

//codesnippet nameinclude
#include <vector>
#include "geolib.hpp"
using namespace geometry;
int main() {
  std::vector< vector > vectors;
  vectors.push_back( vector( point(1,1),point(4,5) ) );
  //codesnippet end

  std::cout << "and the first has length " << vectors[0].size() << '\n';

  return 0;
}
