/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** sumsquares.cxx : sum of squares example
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

int main() {

  int low=10, upper = 500;
  //codesnippet sumsquareloop
  int sum_of_squares{0};
  for (int var=low; var<upper; ++var) {
    sum_of_squares += var*var;
  }
  cout << "The sum of squares from "
       << low << " to " << upper
       << " is " << sum_of_squares << '\n';
  //codesnippet end

  return 0;
}
