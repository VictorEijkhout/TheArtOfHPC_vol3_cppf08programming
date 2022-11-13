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
    //examplesnippet assignbracketoob
    vector<int> numbers = {1,4};
    numbers[-1] += 3;
    numbers[2] = 8;
    cout << numbers[0] << ","
         << numbers[1] << '\n';
    //examplesnippet end
    cout << "bracket" << '\n';
  }

  {
    cout << "Atfun" << '\n';
    //examplesnippet assignatfunoob
    vector<int> numbers = {1,4};
    numbers.at(-1) += 3;
    numbers.at(2) = 8;
    cout << numbers.at(0) << ","
         << numbers.at(1) << '\n';
    //examplesnippet end
    cout << "atfun" << '\n';
  }

  return 0;
}
