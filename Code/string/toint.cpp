/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** strings.cxx : exploration of the string class
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;

#include <sstream>
using std::stringstream;

int main() {

  //codesnippet strconvert2int
  string stringnum="12345";
  int num;
  stringstream numstream(stringnum);
  numstream >> num;
  //codesnippet end
  cout << "That number is: " << num << '\n';
  
  return 0;
}
