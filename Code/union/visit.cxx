/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** visit.cxx : applying visit to a variant
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <sstream>
using std::stringstream;

#include <string>
using std::string;

#include <variant>
using std::variant;
using std::get_if;
using std::get;
using std::bad_variant_access;
using std::visit;

class double_object {
private:
  double x;
public:
  double_object( double x ) : x(x) {};
  auto value() { return x; };
};
class string_object {
private:
  string s;
public:
  string_object( string s ) : s(s) {};
  auto value() { return s; };
};

class stringer {
public:
  string operator()( double_object d ) {
    stringstream ss;
    ss << d.value();
    return ss.str(); };
  string operator()( string_object s ) {
    return s.value(); };
};

//codesnippet sizerclass
class sizer {
public:
  int operator()( double_object d ) {
    return static_cast<int>( d.value() ); };
  int operator()( string_object s ) {
    return s.value().size(); };
};
//codesnippet end

int main() {

  //codesnippet sizeruse
  variant<double_object,string_object>
    union_is_double{ double_object(2.5) },
    union_is_string{ string{"two-point-five"} };
  //codesnippet end

  //codesnippet sizervisit
  cout << "Size of <<" 
       << visit( stringer{},union_is_double )
       << ">> is " 
       << visit( sizer{},union_is_double )
       << '\n';
  cout << "Size of <<" 
       << visit( stringer{},union_is_string )
       << ">> is " 
       << visit( sizer{},union_is_string )
       << '\n';
  //codesnippet end

  return 0;
}
