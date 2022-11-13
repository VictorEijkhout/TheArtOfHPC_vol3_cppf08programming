/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-9 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** destructor.cxx : illustration of objects going out of scope
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//examplesnippet destructor
class SomeObject {
public:
  SomeObject() {
    cout << "calling the constructor"
         << '\n';
  };
  ~SomeObject() {
    cout << "calling the destructor"
         << '\n';
  };
};
//examplesnippet end

int main() {

//examplesnippet destructoruse
  cout << "Before the nested scope"
       << '\n';
  {
    SomeObject obj;
    cout << "Inside the nested scope"
         << '\n';  
  }
  cout << "After the nested scope"
       << '\n';
//examplesnippet end

  return 0;
}
