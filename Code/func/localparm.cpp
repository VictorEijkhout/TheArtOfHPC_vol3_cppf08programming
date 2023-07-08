/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-9 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** localparm.cxx : simple parameter passing
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <vector>
using std::vector;

//examplesnippet localparm
void change_scalar(int i) {
  i += 1;
}
//examplesnippet end

int main() {

  int number;

  //examplesnippet localparm
  number = 3;
  cout << "Number is 3: "
       << number << '\n';
  change_scalar(number);
  cout << "is it still 3? Let's see: "
       << number << '\n';
  //examplesnippet end
  
  return 0;
}
