/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** factor.cxx : double loop over factors
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

int main() {

  //codesnippet factor40
  for (int i=0; i<10; i++) {
    bool found{false};
    for (int j=0; j<10; j++) {
      if (i*j>40) {
	cout << "The pair " << i << "," << j << " multiplies to " << i*j << '\n';
	found = true;
	break;
      }
    }
    if (found) break;
  }

  for (int sum=1; sum<20; sum++) {
    bool found{false};
    for (int i=0; i<sum; i++) {
      int j = sum-i;
      if (i*j>40) {
	cout << "The pair " << i << "," << j << " multiplies to " << i*j << '\n';
	found = true;
	break;
      }
    }
    if (found) break;
  }
  //codesnippet end

  return 0;
}
