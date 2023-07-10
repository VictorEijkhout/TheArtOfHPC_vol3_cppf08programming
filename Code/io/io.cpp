/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** io.cxx : formatted io
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <iomanip>
using std::right;
using std::setbase;
using std::setfill;
using std::setw;

int main() {

  cout << "Unformatted:" << '\n';
  //nosnippet cunformat
  for (int i=1; i<200000000; i*=10)
    cout << "Number: " << i << '\n';
  cout << '\n';
  //nosnippet end
  cout << "--unformatted" << '\n';
  
  cout << "Width is 6:" << '\n';
  cout << setw(6) << 1 << 2 << 3 << '\n';
  cout << '\n';
  
  cout << "Set width:" << '\n';
  //nosnippet formatwidth6
  cout << "Width is 6:" << '\n';
  for (int i=1; i<200000000; i*=10)
    cout << "Number: "
	 << setw(6) << i << '\n';
  cout << '\n';
  //nosnippet end
  cout << "--set width:" << '\n';
  
  cout << "Padding:" << '\n';
  //nosnippet formatpad
  for (int i=1; i<200000000; i*=10)
    cout << "Number: "
	 << setfill('.') << setw(6) << i << '\n';
  cout << '\n';
  //nosnippet end
  cout << "--padding:" << '\n';
  
  cout << "Left align:" << '\n';
  //nosnippet formatleft
  for (int i=1; i<200000000; i*=10)
    cout << "Number: "
	 << left << setfill('.') << setw(6) << i << '\n';
  //nosnippet end
  cout << '\n';
  cout << "--left align:" << '\n';

  cout << "Base 16:" << '\n';
  //nosnippet format16
  cout << setbase(16) << setfill(' ');
  for (int i=0; i<16; ++i) {
    for (int j=0; j<16; ++j)
      cout << i*16+j << " " ;
    cout << '\n';
  }
  //nosnippet end
  cout << '\n';
  cout << "--base 16:" << '\n';
  
  return 0;
}

