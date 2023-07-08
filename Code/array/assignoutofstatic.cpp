/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ***
 **** assignoutofbound.cxx : simple example of assigning to an element out of bounds
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

#include <vector>
using std::vector;

int main() {

  {
    cout << "Bracket" << '\n';
    int numbers[2] = {1,4};
    numbers[-1] += 3;
    numbers[2] = 8;
    cout << numbers[0] << ","
         << numbers[1] << '\n';
    cout << "bracket" << '\n';
  }

  {
    cout << "Atfun" << '\n';
    int *numbers = (int*)malloc(2*sizeof(int));
    numbers[0] = 1; numbers[1] = 4;
    numbers[-1] += 3;
    numbers[2] = 8;
    cout << numbers[0] << ","
         << numbers[1] << '\n';
    cout << "atfun" << '\n';
  }

  return 0;
}
