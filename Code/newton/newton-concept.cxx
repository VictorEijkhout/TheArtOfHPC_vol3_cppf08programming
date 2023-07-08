/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** newton1.cxx : newton scalar example
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <cmath>

#include <complex>
using std::complex;

#include <concepts>

// WRONG
template<typename T>
concept FloatType = std::is_floating_point_v<T>;
// Maybe?
template<typename T> concept floating_point_imaginary = std::floating_point<T> || std::same_as<std::complex<typename T::value_type>, T>;

template<FloatType T>
T f(T x) { return x*x - static_cast<T>(2); };
template<FloatType T>
T fprime(T x) { return static_cast<T>(2) * x; };

int main() {

  double x{1.};
  while ( true ) {
    auto fx = f<double>(x);
    cout << "f( " << x << " ) = " << fx << '\n';
    if (std::abs(fx)<1.e-10 ) break;
    x = x - fx/fprime<double>(x);
  }
  
  complex<double> z{.5,.5};
  while ( true ) {
    auto fz = f<complex<double>>(z);
    cout << "f( " << z << " ) = " << fz << '\n';
    if (std::abs(fz)<1.e-10 ) break;
    z = z - fz/fprime<complex<double>>(z);
  }
  
  int i{5};
  while ( true ) {
    auto fi = f<int>(i);
    cout << "f( " << i << " ) = " << fi << '\n';
    if (std::abs(fi)<1.e-10 ) break;
    i = i - fi/fprime<int>(i);
  }
  
  return 0;
}
