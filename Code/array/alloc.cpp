/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** array.cxx : basic array stuff
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

#include <vector>
using std::vector;

class array_object {
  vector<int> vec;
public:
  array_object(int n) {
    vec = vector<int>(n);
  };
  int size() { return vec.size(); };
};

int main() {
  vector<int>xinit(5,3);
  cout << "array has been initialized to " << xinit.at(2) << '\n';

  vector<int>x(5);
  cout << x.size() << '\n';

  array_object obj(7);
  cout << obj.size() << '\n';
  
  return 0;
}

