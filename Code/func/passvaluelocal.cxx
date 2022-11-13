/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** passvalue.cxx : illustration pass-by-value
 ****
 ****************************************************************/

#include <iostream>
#include <cmath>
using std::cout;

//examplesnippet passvaluelocal
double squared( double x ) {
  x = x*x;
  return x;
}
//examplesnippet end

int main() {

  double number,other;
  //examplesnippet passvaluelocal
  number = 5.1;
  cout << "Input starts as: "
       << number << '\n';
  other = squared(number);
  cout << "Output var is: "
       << other << '\n';
  cout << "Input var is now: "
       << number << '\n';
  //examplesnippet end

  return 0;
}
