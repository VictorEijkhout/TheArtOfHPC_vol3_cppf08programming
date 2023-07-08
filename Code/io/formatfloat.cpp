/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** formatfloat.cxx : floating point output
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
//codesnippet formatfloat
#include <iomanip>
using std::left;
using std::setfill;
using std::setw;
using std::setprecision;
//codesnippet end

int main() {

  float x;
  //codesnippet formatfloat
  x = 1.234567;
  for (int i=0; i<10; i++) {
    cout << setprecision(4) << x << '\n';
    x *= 10;
  }
  //codesnippet end
  
  return 0;
}

