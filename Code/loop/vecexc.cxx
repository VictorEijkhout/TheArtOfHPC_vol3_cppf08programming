/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** vecerr.cxx : indexing error, statically detectable
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;

int main() {

  //codesnippet vecexc
  vector<int> a(5);
  a.at(6) = 1.;
  //codesnippet end

  return 0;
}
