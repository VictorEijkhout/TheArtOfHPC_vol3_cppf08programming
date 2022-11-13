/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** mult.cxx : recursive multiplication
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//codesnippet multrecur
int times( int number,int mult ) {
  cout << "(" << mult << ")";
  if (mult==1)
    return number;
  else
    return number + times(number,mult-1);
}
//codesnippet end

int main() {

  int number,multiplier;
  cout << "Enter number and multiplier" << endl;
  cin >> number; cin >> multiplier;
  cout << "recursive multiplication\n of "
       << number << " and " << multiplier << ": "
       << times(number,multiplier) << endl;

  return 0;
}
