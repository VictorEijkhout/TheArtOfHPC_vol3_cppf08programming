/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** f2c.cxx : fahrenheit to centigrade conversion
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

int main() {
  float c,f;

  cout << "Enter a temperature in Fahrenheit: " << '\n';
  cin >> f;
  c = (f-32)*5/9.;
  cout << "Equivalent Celsius: " << c << '\n';
  
  return 0;
}
