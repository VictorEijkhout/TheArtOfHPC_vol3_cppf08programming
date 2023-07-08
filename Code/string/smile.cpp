/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018/9 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** smile.cxx : unicode experiments
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;

int main() {

  //codesnippet unismile
  string smile{"😀"};
  cout << smile << '\n';
  cout << smile.size() << '\n';
  //codesnippet end

  return 0;
}
