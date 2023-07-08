/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** quickinput.cxx : text file input
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;

//codesnippet filein
#include <fstream>
using std::ifstream;
//codesnippet end

int main() {

  //codesnippet filein
  ifstream input_file;
  input_file.open("fox.txt");
  string oneline;
  while (getline(input_file,oneline)) {
    cout << "Got line: <<" << oneline << ">>" << '\n';
  }
  //codesnippet end

  return 0;
}

