/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** polymorphic1.cxx : example
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

class lib {
public:
  virtual int give() = 0;
};
class lib1 : lib {
public:
  lib1() {};
  int give() { return 1; };
};
class lib2 : lib {
public:
  lib2() {};
  int give() { return 2; };
};

int main() {

  {  
    lib1 mylib;
    cout << mylib.give() << '\n';
  }

#if 0
  {
    // DOES NOT COMPILE: cannot create variable of abstract class
    lib mylib = lib1();
    cout << mylib.give() << '\n';
  }
#endif

  return 0;
}
