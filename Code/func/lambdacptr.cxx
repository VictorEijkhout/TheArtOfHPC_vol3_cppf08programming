/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** lambdacptr.cxx : lambdas vs C function pointers
 ****
 ****************************************************************/

#include <functional>
using std::function;

#include <iostream>
using std::cin;
using std::cout;

//codesnippet lambdacptr
int cfun_add1( int i ) { return i+1; };
int apply_to_5( int(*f)(int) ) {
  return f(5);
};
//codesnippet  end
int main() {

//codesnippet lambdacptr
  auto lambda_add1 = [] (int i) { return i+1; };
  cout << "C ptr: "
       << apply_to_5(&cfun_add1) << '\n';
  cout << "Lambda: "
       << apply_to_5(lambda_add1) << '\n';
//codesnippet end

  return 0;
}
