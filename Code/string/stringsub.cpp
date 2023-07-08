/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** stringsub.cxx : string subscripting
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;

int main() {

  //codesnippet stringsub
  string digits{"0123456789"};
  cout << "char three: "
       << digits[2] << '\n';  
  cout << "char four : "
       << digits.at(3) << '\n';  
  //codesnippet end

  return 0;
}
