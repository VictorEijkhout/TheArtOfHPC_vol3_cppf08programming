/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** collatz.cxx : compute the Collatz sequence of an input
 ****
 **** teaches : recursion
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

int collatz(int n) {
  if (n%2==0)
    return n/2;
  else
    return 3*n+1;
}

int main() {
  int start_number;
  cout << "Give the starting number: " ;
  cin >> start_number;
  
  for (;;) {
    start_number = collatz(start_number);
    cout << " " << start_number ;
    if (start_number==1)
      break;
  } cout << '\n';

  return 0;
}
