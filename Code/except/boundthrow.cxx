/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** boundthrow.cxx : throw an out-of-bounds exception
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
    //codesnippet xoutbounds
    vector<float> x(5);
    x.at(5) = 3.14;
    //codesnippet end
  }

  return 0;

}
