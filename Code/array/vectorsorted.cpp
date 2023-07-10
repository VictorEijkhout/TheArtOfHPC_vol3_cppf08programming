/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** vectorend.cxx : example of vector end iterator
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

void printsorted( vector<int> array ) {
  //codesnippet vectorsorted
  bool sorted{true};
  auto array_end = --array.end();
  for ( auto e=array.begin(); e<array_end; ++e ) {
    auto next_e = e+1;
    cout << "Comparing " << *e << " & " << *next_e << '\n';
    sorted = sorted && *e<=*next_e;
  }
  if (sorted)
    cout << "Array is sorted" << '\n';
  else    
    cout << "Array is not sorted" << '\n';
  //codesnippet end
}

int main() {

  printsorted( vector<int>{1,3,5,7,9} );
  printsorted( vector<int>{1,3,5,9,7} );
  return 0;
}
