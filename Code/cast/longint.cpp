/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** longint.cxx : cast int
 ****
 ****************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  //codesnippet longintcast
  int hundredk = 100000;
  int overflow;
  overflow = hundredk*hundredk;
  cout << "overflow: " << overflow << '\n';
  size_t bignumber = static_cast<size_t>(hundredk)*hundredk;
  cout << "bignumber: " << bignumber << '\n';
  //codesnippet end
  
  return 0;
}
