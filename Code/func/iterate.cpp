/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** lambdait.cxx : lambda example
 ****
 ****************************************************************/

#include <iostream>
#include <cmath>
using std::cout;

#include <functional>
using std::function;

auto succ(int n) {
  return n+1;
}

function< int(int) > compose( int n,function< int(int) >f ) {
  function< int(int) >ff;
  if (n==1) {
    ff = [f]   (int i) -> int { return f(i); };
  } else {
    ff = [f,n] (int i) -> int { return compose(n-1,f)(f(i)); };
  }
  return ff;
}

int main() {

  cout << "Level 0" << '\n';
  for (int i=0; i<10; i++)
    cout << i << " : " << succ(i) << '\n';

  auto geo = [] (int n) -> int { return compose(n,succ)(n); };
  
  cout << "Level 1" << '\n';
  for (int i=0; i<10; i++)
    cout << i << " : " << geo(i) << '\n';

  return 0;
}
