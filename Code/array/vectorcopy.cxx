/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** vectorcopy.cxx : example of vector copying
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int main() {

  //codesnippet vectorcopy
  vector<float> v(5,0), vcopy;
  v.at(2) = 3.5;
  vcopy = v;
  vcopy.at(2) *= 2;
  cout << v.at(2) << ","
       << vcopy.at(2) << '\n';
  //codesnippet end

  return 0;
}
