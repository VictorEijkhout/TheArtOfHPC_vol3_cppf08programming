/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** polyfun.cxx : simple function polymorphism
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//codesnippet polyfunc
int sum(int i,int j) { return i+j; }
double sum(double i,double j) { return i+j; }
//codesnippet end

int main() {
  
  cout << sum(5,12) << '\n';
  cout << sum(5.1,12.) << '\n';

  return 0;
}
