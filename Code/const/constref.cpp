/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** constref.cxx : returning a const by ref
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

//codesnippet constref
class has_int {
private:
  int mine{1};
public:
  const int& int_to_get() { return mine; };
  int& int_to_set() { return mine; };
  void inc() { ++mine; };
};
//codesnippet end

int main() {

//codesnippet constref
  has_int an_int;
  an_int.inc(); an_int.inc(); an_int.inc();
  cout << "Contained int is now: "
       << an_int.int_to_get() << '\n';
  /* Compiler error: an_int.int_to_get() = 5; */
  an_int.int_to_set() = 17;
  cout << "Contained int is now: "
       << an_int.int_to_get() << '\n';
  //codesnippet end
  
  return 0;
}
