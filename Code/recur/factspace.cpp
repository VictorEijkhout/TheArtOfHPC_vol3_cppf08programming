/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** factspace.cxx : factorial with cute indenting
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;

int factorial(int n,string indent) {
  int result;
  cout << indent << "Computing factorial of " << n << '\n';
  if (n==0) 
    result = 1;
  else
    result = n*factorial(n-1,indent+"  ");
  cout << indent << ".. as " << result << '\n';
  return result;
}

int main() {
  int n;
  cout << "What do you want the factorial of? ";
  cin >> n;
  
  int fact = factorial(n,"");
  cout << "Factorial of " << n << " is " << fact << '\n';

  return 0;
}
