/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** bitset.cxx : bitwise operators
 ****
 ****************************************************************/

#include <iostream>
using std::cin,  std::cout;
#include <bitset>
using std::bitset;

int main() {

  //codesnippet bitsetandor
  bitset<8> xb(6);
  bitset<8> yb(3);
  auto xory = (xb|yb).to_ulong();
  cout << "6|3 = " << (xb|yb) << " = "
       << xory << '\n';
  cout << "6&3 = " << (xb&yb) << '\n';
  //codesnippet end

  return 0;
}
