/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** static.cxx : static class members
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//codesnippet staticclass
class Thing {
private:
  static inline int number{0};
  int mynumber;
public:
  Thing() {
    mynumber = number++;
    cout << "I am thing "
         << mynumber << '\n';
  };
};
//codesnippet end
  
int main() {

  Thing one;
  Thing two;
  Thing three;

  return 0;
}
