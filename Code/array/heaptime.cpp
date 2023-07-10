/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** heaptime.cxx : timing heap vs stack array
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <functional>
using std::function;
#include <tuple>
using std::make_pair;
using std::pair;
#include <string>
using std::string;
#include <vector>
using std::vector;

#include <chrono>

#define N 1000

double stacksum( double x ) {
  double array[N];
  array[0] = x;
  for (int i=1; i<N; ++i)
    array[i] = array[i-1] * 1./(x+0.1);
  return array[N-1];
}

double heapsum( double x ) {
  vector<double> arrayvector(N);
  double *array = arrayvector.data();
  array[0] = x;
  for (int i=1; i<N; ++i)
    array[i] = array[i-1] * 1./(x+0.1);
  return array[N-1];
}

double mallocsum( double x ) {
  double* array = (double*)malloc( N*sizeof(double) );
  array[0] = x;
  for (int i=1; i<N; ++i)
    array[i] = array[i-1] * 1./(x+0.1);
  double result = array[N-1];
  free(array);
  return result;
}

double passstack( double x,double array[] ) {
  array[0] = x;
  for (int i=1; i<N; ++i)
    array[i] = array[i-1] * 1./(x+0.1);
  return array[N-1];
}

double passheap( double x,vector<double>& array ) {
  array[0] = x;
  for (int i=1; i<N; ++i)
    array[i] = array[i-1] * 1./(x+0.1);
  return array[N-1];
}

double passmalloc( double x,double* array ) {
  array[0] = x;
  for (int i=1; i<N; ++i)
    array[i] = array[i-1] * 1./(x+0.1);
  return array[N-1];
}

int main() {

  using myclock = std::chrono::steady_clock ;

  double stackarray[N]; 
  vector<double> heaparray(N);
  for ( auto array : { &(stackarray[0]),&(heaparray[0]) } ) {
    for (int a : { 1,2,3,4,6,8 } ) {
      size_t addr = (size_t) array;
      int p=2; for (int i=1; i<a; ++i) p *= 2;
      cout << "align " << p << ": " << addr%p << '\n';
    }
  }
  double *mallocarray = (double*) malloc( N*sizeof(double) );

#define NITER 1000
  for ( auto [functionname,sumfunction]
	  : vector< pair<string, function< double(double) > > >{
	  {"local on stack",stacksum}
	  ,
	  {"local on heap",heapsum}
	  ,
	  {"local malloc",mallocsum}
	  ,
	  {"global on stack",
	      [&stackarray] (double x)  -> double { return passstack(x,stackarray); } }
	  ,
	  {"global on heap",
	      [&heaparray]  (double x)  -> double { return passheap (x,heaparray ); } }
	  ,
	  {"global malloc",
	      [&mallocarray]  (double x) -> double { return passmalloc (x,mallocarray ); } }
	}  // end of vector of functions
	) {
    auto start_time = myclock::now();
    double s=0;
    for (int i=1; i<=NITER; ++i) {
      double x = i;
      s += sumfunction(x);
    }
    auto duration = myclock::now()-start_time;
    auto microsec_duration =
      std::chrono::duration_cast<std::chrono::microseconds>(duration);
    int usec = microsec_duration.count();
    auto nanosec_duration =
      std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
    float nsec_per_div = 1.*nanosec_duration.count()/NITER/N;
    printf("%15s: ",functionname.data());
    printf("Sum = %e in %d usec",s,usec);
    //printf(", nsec/div %4.1f",nsec_per_div);
    printf(", cycles/div %4.1f", nsec_per_div*3.3 );
    printf("\n");
  }

  free(mallocarray);

  return 0;
}
