/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** intlong.cxx : cast int
 ****
 ****************************************************************/

#include <iostream>
using namespace std; //::static_cast;

int main() {
  //codesnippet longcast
  long int hundredg = 100000000000;
  cout << "long number:     "
       << hundredg << '\n';
  int overflow;
  overflow = static_cast<int>(hundredg);
  cout << "assigned to int: "
       << overflow << '\n';
  //codesnippet end
  
  return 0;
}
