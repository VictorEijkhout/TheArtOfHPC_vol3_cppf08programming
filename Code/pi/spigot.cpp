/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** spigot.cxx : finding digits of pi
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <cmath>

int main() {

  int ndigits{0};
  cin >> ndigits;
  double tail_max = pow(10,-static_cast<double>(ndigits));

  int numer{1}, denom{3};
  double
    pi_over_2{ static_cast<double>(1) },
    running_fraction = static_cast<double>(numer)/static_cast<double>(denom);
  for (;;) {
    pi_over_2 += running_fraction;
    if ( double tail_bound = 2 * running_fraction; tail_bound < tail_max ) {
      cout << "pi: " << 2*pi_over_2 << '\n';
      break;
    }
    numer += 1; denom += 2;
    running_fraction *= numer; running_fraction /= denom;
  }

  return 0;
}
