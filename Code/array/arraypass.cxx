/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** arraypass.cxx : passing an array to a function
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//examplesnippet arraypass
void array_set( double ar[],int idx,double val) {
  ar[idx] = val;
}
//examplesnippet end

//examplesnippet arraypassstar
void array_set_star( double *ar,int idx,double val) {
  ar[idx] = val;
}
//examplesnippet end

int main() {

  double array[5];

//examplesnippet arraypass
  array_set(array,1,3.5);
//examplesnippet end
  cout << "element 1 is " << array[1] << '\n';

//examplesnippet arraypassstar
  array_set_star(array,2,4.2);
//examplesnippet end
  cout << "element 2 is " << array[2] << '\n';

  return 0;
}
