/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** tobase.cxx : cast to base class
 ****
 ****************************************************************/

#include <iostream>
using namespace std; //::static_cast;

class Base {
};
class Derived : public Base {
};

int main() {
  
  Base base_object;
  Derived derived_object;
  base_object = static_cast<Base>(derived_object);

  return 0;
}
