/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** stringrange.cxx : range over string
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;

int main() {

  cout << "Index" << '\n';
  //codesnippet stringindex
  string abc = "abc";
  cout << "By character: ";
  for (int ic=0; ic<abc.size(); ic++)
    cout << abc[ic] << " ";
  cout << '\n';
  //codesnippet end
  cout << ".. index" << '\n';

  cout << "Range" << '\n';
  //codesnippet stringrange
  cout << "By character: ";
  for ( char c : abc )
    cout << c << " ";
  cout << '\n';
  //codesnippet end
  cout << ".. range" << '\n';
  
  cout << "Set" << '\n';
  //codesnippet stringrangeset
  for ( char &c : abc )
    c += 1;
  cout << "Shifted: " << abc << '\n';
  //codesnippet end
  cout << ".. set" << '\n';
  
  return 0;
}
