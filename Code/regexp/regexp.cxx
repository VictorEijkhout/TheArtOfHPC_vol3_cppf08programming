/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** regexp.cxx : regular expression
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <regex>
using std::regex;
using std::regex_match;

int main() {

  cout << "Looks like a name:" << '\n';
  //codesnippet regexname
  vector<string> names {"Victor", "aDam", "DoD"};
  auto cap = regex("[A-Z][a-z]+)");
  for ( auto n : names ) {
    auto match = regex_match( n, cap );
    cout << n;
    if (match) cout << ": yes";
    else       cout << ": no" ;
    cout << '\n';
  }
  //codesnippet end

  return 0;
}
