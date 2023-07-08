/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** switch.cxx : illustrating switch statement
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

int main() {
  int n;
  cin >> n;
  //codesnippet switchstatement
  switch (n) {
  case 1 :
  case 2 :
    cout << "very small" << '\n';
    break;
  case 3 :
    cout << "trinity" << '\n';
    break;
  default :
    cout << "large" << '\n';
  }
  //codesnippet end
  return 0;
}
