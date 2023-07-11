/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** size.cxx : about the sizes of types
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

int main() {

  {
    size_t bigcount = 5000 * 5000 * 5000;
    cout << "Wrong way: " << bigcount << '\n';
  }
  {
    size_t bigcount = 1000 * 1000 *1000;
    bigcount *= 125;
    cout << "Right way: " << bigcount << '\n';
  }

  cout << "A size_t is of size: " << sizeof(size_t) << '\n';

  return 0;
}

