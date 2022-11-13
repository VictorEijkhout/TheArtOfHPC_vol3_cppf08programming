/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** autofun.cxx : function with auto result
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//codesnippet autofun
auto equal(int i,int j) {
  return i==j;
};
//codesnippet end

int main() {

  cout << equal(1,2) << '\n';
  cout << equal(3,3) << '\n';
  
  return 0;
}
