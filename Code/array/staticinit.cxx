/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** staticinit.cxx : initialization of static arrays
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <vector>
using std::vector;

int main() {

  //codesnippet arrayinit
  {
    int numbers[] = {5,4,3,2,1};
    cout << numbers[3] << '\n';
  }
  {
    int numbers[5]{5,4,3,2,1};
    numbers[3] = 21;
    cout << numbers[3] << '\n';
  }
  //codesnippet end
  

  return 0;
}
