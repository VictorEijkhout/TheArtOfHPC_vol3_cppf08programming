/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** veccomplex.cxx : vector of complexes
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

#include <chrono>

#include <numeric>

#include <vector>
using std::vector;

#include <complex>
using std::complex;

int main() {

  int N;
  cin >> N;

  using myclock = std::chrono::high_resolution_clock ;

  using namespace std::complex_literals;
  //codesnippet cplxvec
  vector< complex<double> > vec1(N, 1.+2.5i );
  auto vec2( vec1 );
  //codesnippet end

  /*
   * prep data
   */
  for ( int i=0; i<vec1.size(); i++ ) {
    vec2[i] *= vec1[i];
  }

  /*
   * Now actual timing
   */
  auto start_time = myclock::now();
  //codesnippet cplxvec
  for ( int i=0; i<vec1.size(); i++ ) {
    vec2[i] = vec1[i] * ( 1.+1.i );
  }
  //codesnippet end
  auto duration = myclock::now()-start_time;
  auto nanosec_duration =
    std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
  auto usec = nanosec_duration.count();
  auto Gflops = 6.*N / usec;

  cout << "Time\n";
  cout << "usec: " << usec << "; Gflops: " << Gflops << '\n';
  cout << "time\n";

  cout << "Sum\n";
  //codesnippet cplxvec
  auto sum = accumulate
    ( vec2.begin(),vec2.end(),
      complex<double>(0.) );
  cout << "result: " << sum << '\n';
  //codesnippet end
  cout << "sum\n";

  if (sum==complex<double>(0.)) cout << '\n';

  return 0;
}
