/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** fio.cxx : file io
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

//codesnippet fio
#include <fstream>
using std::ofstream;
//codesnippet end

int main() {

  //codesnippet fio
  ofstream file_out;
  file_out.open
    ("fio_example.out");
  //codesnippet end

  int number;
  cout << "A number please: ";
  cin >> number;
  cout << '\n';
  //codesnippet fio
  file_out << number << '\n';
  file_out.close();
  //codesnippet end
  cout << "Written." << '\n';

  return 0;
}

