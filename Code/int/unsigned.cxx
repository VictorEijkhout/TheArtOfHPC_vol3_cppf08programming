/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** unsigned.cxx : the dangers of int and unsigned
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <iomanip>
using std::boolalpha;

#include <limits>
using std::numeric_limits;

int main() {

  cout << "Limit\n";
  //codesnippet unsignedlimit
  cout << "max int     : "
       << numeric_limits<int>::max() << '\n';
  cout << "max unsigned: "
       << numeric_limits<unsigned int>::max() << '\n';
  //codesnippet end
  cout << "limit\n";

  cout << "Cmp\n";
  //codesnippet unsignedcomp
  unsigned int one{1};
  int mone{-1};
  cout << "less: " << boolalpha << (mone<one) << '\n';
  //codesnippet end
  cout << "cmp\n";

  return 0;
}
