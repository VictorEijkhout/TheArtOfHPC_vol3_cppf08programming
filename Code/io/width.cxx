/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** width.cxx : setting output width
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
//codesnippet formatwidth6
#include <iomanip>
using std::setw;
//codesnippet end

int main() {

  //codesnippet formatwidth6
  cout << "Width is 6:" << '\n';
  for (int i=1; i<200000000; i*=10)
    cout << "Number: "
         << setw(6) << i << '\n';
  cout << '\n';

  // `setw' applies only once:
  cout << "Width is 6:" << '\n';
  cout << ">"
       << setw(6) << 1 << 2 << 3 << '\n';
  cout << '\n';
  //codesnippet end
  
  return 0;
}

