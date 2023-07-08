/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ***
 **** assign.cxx : simple example of assigning to an element
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int main() {

  {
    cout << "Bracket" << '\n';
    //examplesnippet assignbracket
    vector<int> numbers = {1,4};
    numbers[0] += 3;
    numbers[1] = 8;
    cout << numbers[0] << ","
         << numbers[1] << '\n';
    //examplesnippet end
    cout << "bracket" << '\n';
  }

  {
    cout << "Atfun" << '\n';
    //examplesnippet assignatfun
    vector<int> numbers = {1,4};
    numbers.at(0) += 3;
    numbers.at(1) = 8;
    cout << numbers.at(0) << ","
         << numbers.at(1) << '\n';
    //examplesnippet end
    cout << "atfun" << '\n';
  }

  return 0;
}
