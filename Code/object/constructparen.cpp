/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** constructparen.cxx : example
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//codesnippet constructparen
class MyClass {
public:
  MyClass() { cout << "Construct!" << '\n'; };
};

int main() {

  MyClass x;
  MyClass y();
  //codesnippet end
  
  return 0;
}
