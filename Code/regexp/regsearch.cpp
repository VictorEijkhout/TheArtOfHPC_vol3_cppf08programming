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
using std::smatch;

#include <cassert>

int main() {

  string sentence = "The quick brown fox jumps over the lazy dog";
  //codesnippet regsearch
  {
    auto findthe = regex("the");
    auto found = regex_search
      ( sentence,findthe );
    assert( found==true );
    cout << "Found <<the>>" << '\n';
  }
  {
    smatch match;
    auto findthx = regex("o[^o]+o");
    auto found = regex_search
      ( sentence, match ,findthx );
    assert( found==true );
    cout << "Found <<o[^o]+o>>"
	 << " at " << match.position(0)
	 << " as <<" << match.str(0) << ">>"
	 << " preceeded by <<" << match.prefix() << ">>"
	 << '\n';
  }
  //codesnippet end

  return 0;
}
