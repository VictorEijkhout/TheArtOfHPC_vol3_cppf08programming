/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** fixed.cxx : fixed point iteration
 ****
 ****************************************************************/

#include <bitset>
#include <iostream>
using namespace std;

float next(float x) {
  if (x<.5)
    return 2*x;
  else
    return 2*x-1;
}

int main() {
  float x;
  cout << "Number: ";
  cin >> x;
  for (int i=0; i<40; ++i) {
    int *c = (int*)&x;
    cout << x << ", " << std::bitset<32>(c[0]) //<< std::bitset<4>(c[1]) << std::bitset<4>(c[2]) << std::bitset<4>(c[3])
	 << '\n';
    x = next(x);
  }
  return 0;
}

