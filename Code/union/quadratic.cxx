/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** visit.cxx : applying visit to a variant
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <sstream>
using std::stringstream;

#include <cmath>

#include <string>
using std::string;

#include <variant>
using std::variant;
using std::get_if;
using std::get;
using std::bad_variant_access;
using std::visit;

#include "quadlib.h"

int main() {

  //codesnippet quadraticloop
  for ( auto coefficients :
       { make_tuple(2.0, 1.5, 2.5),
         make_tuple(1.0, 4.0, 4.0),
         make_tuple(2.2, 5.1, 2.5)
        } ) {
    auto result = compute_roots(coefficients);
  //codesnippet end
    auto [a,b,c] = coefficients;
    cout << "With a=" << a << " b=" << b << " c=" << c << '\n';
    switch (result.index()) {
    case 0 :
      cout << "No root\n";
      break;
    case 1 :
      {
	auto single_root = get<1>(result);
	cout << "Single root: " << single_root << '\n';
      }
      break;
    case 2 :
      {
	auto [root1,root2] = get<2>(result);
	cout << "Root1: " << root1 << " root2: " << root2 << '\n';
      }
      break;
      //  default : cout << "This is not supposed to happend\n";
    }
  }

  return 0;
}
