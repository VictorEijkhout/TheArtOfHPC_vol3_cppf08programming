/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** except.cxx : exception example
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int main()
{

  {
    //codesnippet xcatchbounds
    vector<float> x(5);
    for (int i=0; i<10; ++i) {
      try {
        x.at(i) = 3.14;
      } catch (...) {
        cout << "Exception indexing at: "
             << i << '\n';
        break;
      }
    }
    //codesnippet end
  }

  return 0;

}
