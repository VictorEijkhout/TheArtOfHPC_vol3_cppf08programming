/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** argcv.cxx : example of traditional commandline arg parsing
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int main(int argc,char *argv[]) {

  //codesnippet argcv
  cout << "Program name: " << argv[0] << '\n';
  for (int iarg=1; iarg<argc; iarg++)
    cout << "arg: " << iarg 
         << argv[iarg] << " => "
         << atoi( argv[iarg] ) << '\n';
  //codesnippet end


  return 0;
}
