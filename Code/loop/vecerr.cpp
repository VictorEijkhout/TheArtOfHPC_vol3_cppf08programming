/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** vecerr.cxx : indexing error, statically detectable
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;
#include <vector>
using std::vector;

int main() {

  //codesnippet vecerr
  vector<int> a(5);
  a[6] = 1.;
  cout << "Success\n";
  //codesnippet end

  return 0;
}
