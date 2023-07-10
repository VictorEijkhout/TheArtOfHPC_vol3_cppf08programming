/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** arraypass.cxx : pass C array to function
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

//codesnippet arraypass
void set_array( double *x,int size) {
  for (int i=0; i<size; ++i)
    x[i] = 1.41;
};
//codesnippet end

int main() {

  //codesnippet arraypass
  double array[5] = {11,22,33,44,55};
  set_array(array,5);
  cout << array[0] << "...." << array[4] << '\n';
  //codesnippet end

  return 0;
}
