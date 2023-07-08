/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018/9 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** intchar.cxx : int/char equivalence
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <iomanip>
using std::setw;

#include <vector>
using std::vector;

#include <string>
using std::string;

int main() {

  //codesnippet intcharxy
  char ex = 'x';
  int x_num = ex, y_num = ex+1;
  char why = y_num;
  cout << "x is at position " << x_num
       << '\n';
  cout << "one further lies " << why
       << '\n';
  //codesnippet end

  return 0;
}
