/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** except.cxx : exception example
 ****
 **** This is a bad example: cin does not use exceptions
 **** there is cin.exceptions( stuff )
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

int main()
{
  int StudentAge;

  cout << "Student Age: ";
  cin >> StudentAge;

  try {
    if(StudentAge < 0)
      throw;
    cout << "\nStudent Age: " << StudentAge << "\n\n";
  } catch(...) {
    cout << "\nSomething went wrong";
  }

  cout << '\n';

  return 0;

}
