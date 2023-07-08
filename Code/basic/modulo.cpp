/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** modulo.cxx : playing with modulo
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

int main() {
  int number1,number2;

  cout << "Number 1: " ;
  cin >> number1;
  cout << "Number 2: " ;
  cin >> number2;

  //codesnippet modulo
  int quotient,modulo;
  quotient = number1/number2;
  modulo = number1 - number2*quotient;

  cout << "Compute modulus: " << modulo << '\n';
  cout << "built-in modulus: " << number1%number2 << '\n';
  //codesnippet end
  cout << "truncate: " << number1-modulo << '\n';

  return 0;
}
