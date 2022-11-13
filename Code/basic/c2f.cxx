/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** c2f.cxx : centigrade to fahrenheit conversion
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

int main() {
  float c,f;

  cout << "Enter a temperature in Celsius: " << '\n';
  cin >> c;
  f = 9*c/5+32;
  cout << "Equivalent Fahrenheit: " << f << '\n';
  
  return 0;
}
