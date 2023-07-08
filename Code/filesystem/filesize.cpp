/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** filesize.cxx : testing file size with C++17
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <filesystem>

int main() {

  auto filesize = std::filesystem::file_size("testfile");
  cout << "file size is: " << filesize << '\n';
  
  return 0;
}

