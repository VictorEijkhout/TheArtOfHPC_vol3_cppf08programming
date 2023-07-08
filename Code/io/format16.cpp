/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** format16.cxx : base 16 formatted io
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
//codesnippet format16
#include <iomanip>
using std::setbase;
using std::setfill;
//codesnippet end

int main() {

  //codesnippet format16
  cout << setbase(16)
       << setfill(' ');
  for (int i=0; i<16; i++) {
    for (int j=0; j<16; j++)
      cout << i*16+j << " " ;
    cout << '\n';
  }
  //codesnippet end
  
  return 0;
}

