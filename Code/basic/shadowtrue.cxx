/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** shadow.cxx : illustrate scope
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

int main() {

  {
    cout << "True" << '\n';
    //codesnippet shadowtrue
    bool something{true};
    int i = 3;
    if ( something ) {
      int i = 5;
      cout << "Local: " << i << '\n';
    }
    cout << "Global: " << i << '\n';
    if ( something ) {
      float i = 1.2;
      cout << "Local again: " << i << '\n';
    }
    cout << "Global again: " << i << '\n';
    //codesnippet end
    cout << "true" << '\n';
  }

  return 0;
}
