/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** lambdacapture.cxx : exploring the capture
 ****
 ****************************************************************/

#include <functional>
using std::function;

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <string>
using std::string;
using std::to_string;

int main() {

  cout << "Value\n";
  //codesnippet lambdavalue
  int one=1;
  auto increment_by_1 = 
    [one] ( int input ) -> int {
      return input+one;
  };
  cout << increment_by_1 (5)  << '\n';
  cout << increment_by_1 (12)  << '\n';
  cout << increment_by_1 (25)  << '\n';
  //codesnippet end
  cout << "value\n";

  cout << "Mutate\n";
  //codesnippet lambdautate
  [one] ( int input ) -> void {
    // WRONG: does not compile:
    // one++;
    cout << input+one << '\n';
  } (5);
  //codesnippet end
  cout << "mutate\n";

  cout << "Reference\n";
  //codesnippet lambdareference
  int stride = 1;
  auto more_and_more = 
    [&stride] ( int input ) -> void {
      cout << input << "=>" << input+stride << '\n';
      stride++;
  };
  more_and_more(5);
  more_and_more(6);
  more_and_more(7);
  more_and_more(8);
  more_and_more(9);
  cout << "stride is now: " << stride << '\n';
  //codesnippet end
  cout << "reference\n";

  // capture everything by value
  auto cap_const =
    [=] ( float x ) -> float {
      return x; //whatever
    };
  // capture everything by reference
  auto cap_ref =
    [&] ( float x ) -> float {
      return x; //whatever
    };

  return 0;
}
