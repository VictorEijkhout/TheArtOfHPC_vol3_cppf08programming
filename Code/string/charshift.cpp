/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** charshift.cxx : chars over 127
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

  //codesnippet charashift
  char a = 'a';
  for ( int i=0; i<128; i++) {
    char c = a+i;
    int cpos = a+i;
    cout << "shift 1 by " << setw(3) << i
         << " giving position " << setw(3) << cpos
         << "=" << c << '\n';
  }
  //codesnippet end

  return 0;
}
