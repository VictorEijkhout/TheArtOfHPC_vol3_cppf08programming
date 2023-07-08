/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** newton-double.cxx : templatize functions
 ****
 **** NOT A GOOD CODE: will not work for T=complex
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <cmath>

#include <complex>
using std::complex;

//codesnippet newtont0
template<typename T>
T f(T x) { return x*x - 2; };
template<typename T>
T fprime(T x) { return 2 * x; };
//codesnippet end

int main() {

//codesnippet newtont0use
  double x{1.};
  while ( true ) {
    auto fx = f<double>(x);
    cout << "f( " << x << " ) = " << fx << '\n';
    if (std::abs(fx)<1.e-10 ) break;
    x = x - fx/fprime<double>(x);
  }
//codesnippet end
  
  return 0;
}
