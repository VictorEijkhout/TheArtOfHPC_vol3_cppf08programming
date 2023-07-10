/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** vectorcopy.cxx : example of vector copying
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <cmath>
using std::sqrt;
#include <chrono>
#include <vector>
using std::vector;

int main() {

  {
    using clock = std::chrono::high_resolution_clock;
    clock::time_point point;

    static constexpr int T = 1000;
    static constexpr int N1 = 30;
    static constexpr int N2 = 30;
    static constexpr int N3 = 30;

    point = clock::now();

    double array[T][N1][N2][N3];
    for ( int i1=0; i1<N1; ++i1 ) 
      for ( int i2=0; i2<N2; ++i2 ) 
	for ( int i3=0; i3<N3; ++i3 ) 
	  array[0][i1][i2][i3] = 15.;
    for ( int t=1; t<T; ++t)
      for ( int i1=0; i1<N1; ++i1 ) 
	for ( int i2=0; i2<N2; ++i2 ) 
	  for ( int i3=0; i3<N3; ++i3 ) {
	    double x = array[t-1][i1][i2][i3];
	    array[t][i1][i2][i3] = sqrt(x);
	  }
    double s=0;
    for ( int i1=0; i1<N1; ++i1 ) 
      for ( int i2=0; i2<N2; ++i2 ) 
	for ( int i3=0; i3<N3; ++i3 ) 
	  s += array[T-1][i1][i2][i3];
	    
    auto duration = clock::now()-point;
    auto nanoseconds_duration =
      std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
    cout << "Time in usec: "
	 << static_cast<int>( nanoseconds_duration.count()*1.e-3 ) << '\n';
    cout << s << '\n';
  }

  return 0;
}
