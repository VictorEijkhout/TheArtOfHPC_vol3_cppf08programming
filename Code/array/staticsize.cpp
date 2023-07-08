/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** staticsize.cxx : sizeof and arrays
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <vector>
using std::vector;

int main() {

  //codesnippet sizeofarray
  int a1[10];
  cout << "static: " << sizeof(a1) << '\n';
  int *a2 = (int*) malloc( 10*sizeof(int) );
  cout << "malloc: " << sizeof(a2) << '\n';
  vector<int> a3(10);
  cout << "vector: " << sizeof(a3) << '\n';
  //codesnippet end
  
  return 0;
}
