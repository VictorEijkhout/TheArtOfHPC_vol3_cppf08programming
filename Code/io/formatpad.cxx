/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** formatpad.cxx : padded io
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
//codesnippet formatpad
#include <iomanip>
using std::setfill;
using std::setw;
//codesnippet end

int main() {

  //codesnippet formatpad
  for (int i=1; i<200000000; i*=10)
    cout << "Number: "
         << setfill('.')
	 << setw(6) << i
	 << '\n';
  //codesnippet end
  
  return 0;
}

