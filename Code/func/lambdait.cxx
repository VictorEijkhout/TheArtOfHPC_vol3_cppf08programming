/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** lambdait.cxx : lambda example
 ****
 ****************************************************************/

#include <iostream>
#include <cmath>
using std::cout;

float f(float x) { return 2*x; };

float nf(float x,int n) {
  if (n==0)
    return x;
  else
    return f( nf(x,n-1) );
};

int main() {

  //codesnippet lambdacapt
  int exponent=5;
  auto powerfive =
    [exponent] (float x) -> float {
      return pow(x,exponent); };
  //codesnippet end
  //codesnippet lambdapowercall
  cout << "To the power "
       << exponent << '\n';
  for (float x=1.; x<=5.; x+=1.)
    cout << x << ":" << powerfive(x) << '\n';
  //codesnippet end
  
  return 0;
}
