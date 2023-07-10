/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** iof.cxx : formatted float io
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <iomanip>
using std::fixed;
using std::scientific;
using std::setprecision;
using std::right;
using std::setbase;
using std::setfill;
using std::setw;

int main() {

  double x;
  cout << "Float precision applies to non-exponent:" << '\n';
  x = 1.234567;
  for (int i=0; i<10; ++i) {
    cout << setprecision(4) << x << '\n';
    x *= 10;
  }
  cout << '\n';
  
  cout << "Fixed precision applies to fractional part:" << '\n';
  x = 1.234567;
  cout << fixed;
  for (int i=0; i<10; ++i) {
    cout << setprecision(4) << x << '\n';
    x *= 10;
  }
  cout << '\n';
  
  cout << "Combine width and precision:" << '\n';
  x = 1.234567;
  cout << fixed;
  for (int i=0; i<10; ++i) {
    cout << setw(10) << setprecision(4) << x << '\n';
    x *= 10;
  }
  cout << '\n';
  
  cout << "Combine width and precision:" << '\n';
  cout << "IOFSCI" << '\n';
  //codesnippet precisionwidth
  x = 1.234567;
  cout << scientific;
  for (int i=0; i<10; ++i) {
    cout << setw(10) << setprecision(4)
         << x << '\n';
    x *= 10;
  }
  cout << '\n';
  //codesnippet end
  cout << "iofsci" << '\n';
  
  return 0;
}

