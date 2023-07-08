/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** trial.cxx : find factors by trial division
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

int main() {
  long number = 700179159413;

  long factor1 = 1;
  for (long divisor=3; divisor<number/2; divisor+=2)
    if (number%divisor==0) {
      cout << "The smallest divisor is " << divisor << '\n';
      factor1 = divisor;
      break;
    }
  long factor2 = number/factor1;
  cout << ".. the other factor is " << factor2 << '\n';
  long check = factor1*factor2;
  cout << ".. just checking: " << number << ( number==check ? "==" : "!=" ) << check << '\n';
  return 0;
}
