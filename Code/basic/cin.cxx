/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** cin.cxx : test cin 
 ****
 ****************************************************************/

#include <cmath>
using std::sqrt;

#include <iostream>
using std::cin, std::cout;

#include <string>
using std::string;

int main() {
  //codesnippet cinspace
  string name; int age;
  cout << "Your name?\n";
  cin >> name;
  cout << "age?\n";
  cin >> age;
  cout << age << " is a nice age, "
       << name << '\n';
  //codesnippet end

  return 0;
}

