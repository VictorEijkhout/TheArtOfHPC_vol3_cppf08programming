/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** string.cxx : basic string stuff
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

using std::string;

int main() {
  string first{"this"}, second{"is"}, third,sum;
  third = "text";
  sum = first+" "+second+" "+third;

  cout << "Sum string is: <<" << sum << ">>" << '\n';
  cout << "Sum string has " << sum.size() << " characters" << '\n';
  cout << "The second character is <<" << sum[1] << ">>" << '\n';

  return 0;
}

