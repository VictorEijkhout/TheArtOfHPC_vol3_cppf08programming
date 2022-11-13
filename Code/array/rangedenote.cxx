/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-9 Victor Eijkhout eijkhout@tacc.utexas.edu
 ***
 **** rangedenote.cxx : range over denotation
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int main() {

  //examplesnippet rangedenote
  for ( auto i : {2,3,5,7,9} )
    cout << i << ",";
  cout << '\n';
  //examplesnippet end
    
  return 0;
}
