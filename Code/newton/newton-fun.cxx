/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** newton1.cxx : newton scalar example
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <cmath>

#include <functional>
using std::function;

//codesnippet newtonfg
double f(double x) { return x*x-2; };
double fprime(double x) { return 2*x; };
//codesnippet end

double find_zero( function< double(double) > f, function< double(double) > fprime ) {
  //codesnippet newtonalg
  double x{1.};
  while ( true ) {
    auto fx = f(x);
    cout << "f( " << x << " ) = " << fx << '\n';
    if (std::abs(fx)<1.e-10 ) break;
    x = x - fx/fprime(x);
  }
  //codesnippet end
  return x;
};

int main() {

  find_zero( f,fprime );
  
  return 0;
}
