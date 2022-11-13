/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** helloin.cxx : use of loop to print
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

int main() {
  int howmany;
  cout << "How many times?" << '\n';
  cin >> howmany;
  for ( int ihow=0; ihow<howmany; ihow++)
    cout << "Hello world" << '\n';
  return 0;
}
