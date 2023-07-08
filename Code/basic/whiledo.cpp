/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** whiledo.cxx : while loop with pre-test
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

int main() {
  int invar;

  //codesnippet whiledo
  cout << "Enter a positive number: " ;
  cin >> invar; cout << '\n';
  cout << "You said: " << invar << '\n';
  while (invar<=0) {
    cout << "Enter a positive number: " ;
    cin >> invar; cout << '\n';
    cout << "You said: " << invar << '\n';
  }
  cout << "Your positive number was "
       << invar << '\n';
  //codesnippet end
  
  return 0;
}

