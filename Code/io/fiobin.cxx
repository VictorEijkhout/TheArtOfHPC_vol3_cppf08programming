/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** fiobin.cxx : binary file io
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <iomanip>
using std::right;
using std::setbase;
using std::setfill;
using std::setw;

#include <fstream>
using std::ofstream;
using std::ios;

int main() {

  //codesnippet fiobin
  ofstream file_out;
  file_out.open
    ("fio_binary.out",ios::binary);
  //codesnippet end

  int number;
  cout << "A number please: ";
  cin >> number;
  //  file_out << number ;
  //codesnippet fiobin
  file_out.write( (char*)(&number),4);
  //codesnippet end
  file_out.close();
  cout << "Written." << '\n';

  return 0;
}

