/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** dowhile.cxx : while loop with pre-test
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

int main() {

  //codesnippet dowhile
  int invar;
  do {
    cout << "Enter a positive number: " ;
    cin >> invar; cout << '\n';
    cout << "You said: " << invar << '\n';
  } while (invar<=0);
  cout << "Your positive number was: "
       << invar << '\n';
  //codesnippet end
  
  return 0;
}

