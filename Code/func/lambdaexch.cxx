/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** lambdaexch.cxx : lambda example with exchange
 ****
 ****************************************************************/

#include <functional>
using std::function;

#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string,std::to_string;
#include <vector>
using std::vector;

int main() {

  //codesnippet mutablecomma
  vector x{1,2,3,4,5};
  auto printdigit =
    [start=true] (auto xx) mutable -> string{
      if (start) {
	start = false;
	return to_string(xx);
      } else
	return ","+to_string(xx);
    };
  for ( auto xx : x )
    cout << printdigit(xx);
  cout << '\n';
  //codesnippet end

  return 0;
}
