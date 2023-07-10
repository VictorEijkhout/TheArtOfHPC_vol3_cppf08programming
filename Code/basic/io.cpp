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
using std::cin, std::cout;

#include <iomanip>
using std::setw;
using std::setfill;
using std::left;
using std::right;
using std::setbase;

int main() {

  cout << "Unformatted:" << '\n';
  //codesnippet cunformat
  for (int i=1; i<200000000; i*=10)
    cout << "Number: " << i << '\n';
  cout << '\n';
  //codesnippet end
  cout << "--unformatted" << '\n';
  
  cout << "Width is 6:" << '\n';
  cout << setw(6) << 1 << 2 << 3 << '\n';
  cout << '\n';
  
  cout << "Set width:" << '\n';
  //codesnippet formatwidth6
  cout << "Width is 6:" << '\n';
  for (int i=1; i<200000000; i*=10)
    cout << "Number: "
	 << setw(6) << i << '\n';
  cout << '\n';
  //codesnippet end
  cout << "--set width:" << '\n';
  
  cout << "Padding:" << '\n';
  //codesnippet formatpad
  for (int i=1; i<200000000; i*=10)
    cout << "Number: "
	 << setfill('.') << setw(6) << i << '\n';
  cout << '\n';
  //codesnippet end
  cout << "--padding:" << '\n';
  
  cout << "Left align:" << '\n';
  //codesnippet formatleft
  for (int i=1; i<200000000; i*=10)
    cout << "Number: "
	 << left << setfill('.') << setw(6) << i << '\n';
  //codesnippet end
  cout << '\n';
  cout << "--left align:" << '\n';

  cout << "Base 16:" << '\n';
  //codesnippet format16
  cout << setbase(16) << setfill(' ');
  for (int i=0; i<16; ++i) {
    for (int j=0; j<16; ++j)
      cout << i*16+j << " " ;
    cout << '\n';
  }
  //codesnippet end
  cout << '\n';
  cout << "--base 16:" << '\n';
  
  cout << "Format16:" << '\n';
  cout << setbase(16) << setfill('0') << right ;
  for (int i=0; i<16; ++i) {
    for (int j=0; j<16; ++j)
      cout << setw(2) << i*16+j << " " ;
    cout << '\n';
  }
  cout << '\n';
  cout << "--format16:" << '\n';
  return 0;
}

