/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** hello.cxx : an empty program
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

#include <cmath>
using std::sqrt;

bool legal_square_root( float &x ) {
  if (x<0)
    return false;
  else {
    x = sqrt(x);
    return true;
  }
}

int main() {

  float x;

  for (;;) {
    cout << "Give a number: ";
	    cin >> x;
    if (!legal_square_root(x)) {
      cout << "Sorry, that was negative!" << '\n';
      break;
    } else
      cout << "... and its square root is: " << x << '\n';
  }

  return 0;
}
