/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** bits.cxx : bitset
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <iomanip>
using std::fixed;
using std::setprecision;
using std::setw;

//codesnippet ibitset
#include <bitset>
using std::bitset;
//codesnippet end

int main() {

  //codesnippet ibitset
  auto x255 = bitset<16>(255);
  cout << x255 << '\n';
  //codesnippet end
  
  return 0;
}

