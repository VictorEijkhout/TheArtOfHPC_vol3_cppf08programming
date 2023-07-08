/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** intdoublestring.cxx : exploring variant
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <variant>
using std::variant;
using std::get_if;
using std::get;
using std::bad_variant_access;

int main() {

  //codesnippet unionids
  variant<int,double,string> union_ids;
  //codesnippet end

  //codesnippet unionids_index
  union_ids = 3.5;
  switch ( union_ids.index() ) {
  case 1 :
    cout << "Double case: " << std::get<double>(union_ids) << '\n';
  }
  //codesnippet end

  //codesnippet unionids_bad
  union_ids = 17;
  cout << "Using option " << union_ids.index() << ": " << get<int>(union_ids) << '\n';
  try {
    cout << "Get as double: " << get<double>(union_ids) << '\n';
  } catch ( bad_variant_access b ) {
    cout << "Exception getting as double while index=" << union_ids.index() << '\n';
  }
  //codesnippet end

  //codesnippet unionids_getif
  union_ids = "Hello world";
  if ( auto union_int = get_if<int>(&union_ids) ; union_int )
    cout << "Int: " << *union_int << '\n';
  else if ( auto union_string = get_if<string>(&union_ids) ; union_string )
    cout << "String: " << *union_string << '\n';
  //codesnippet end

  return 0;
}
