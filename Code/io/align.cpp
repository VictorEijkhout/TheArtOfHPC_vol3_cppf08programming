/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** fix.cxx : fixed precision io
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <iomanip>
using std::fixed;
using std::setprecision;
using std::setw;

int main() {

  double x;
  //codesnippet align
  x = 1.234567;
  cout << fixed;
  for (int i=0; i<10; ++i) {
    cout << setw(10) << setprecision(4) << x
	 << '\n';
    x *= 10;
  }
  //codesnippet end

  return 0;
}

