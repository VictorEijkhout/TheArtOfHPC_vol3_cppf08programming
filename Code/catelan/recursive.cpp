/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** recursive.cxx : recursive calculation
 ****
 ****************************************************************/

#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>

using namespace std;

using inttype = unsigned long;

inttype catelan( int c ) {
  if (c==0) return 1;
  else {
    inttype sum = 0;
    for ( int n=0; n<c; ++n )
      sum += catelan(n) * catelan(c-1-n);
    return sum;
  }
}

int main() {

  using myclock = std::chrono::steady_clock ;

  for ( int c=0; c<=20; ++c ) {
    auto start_time = myclock::now();
    cout << "C_" << c << " = " << catelan(c) ;
    auto duration = myclock::now()-start_time;
    auto milli_seconds =
      std::chrono::duration_cast<std::chrono::microseconds>(duration).count()/1000;
    cout << " t: " << milli_seconds*.001f << " sec\n";
  }

  return 0;
}

  
