/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016=2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** even.cxx : even test with promise/future
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <chrono>
#include <vector>
using std::vector;

#include <thread>
#include <future>

void is_even_p( int n, std::promise<int>& result) {
  result.set_value( n%2==0 );
}

void is_even_f( int n, std::future<int>& result) {
  std::promise<int> p;
  result = p.get_future();
  result.set_value( n%2==0 );
}

#ifndef NTHREADS
#define NTHREADS 5
#endif

int main() {

  using myclock = std::chrono::steady_clock ;

#if 0
  // WRONG DOES NOT COMPILE
  std::promise<int> p;
  std::thread t(is_even,3,p );
  t.join();
  cout << p.get_future().get() << '\n';
#endif

  std::future<int> f;
  //
  // what's missiing here?
  //
  std::thread t( 

  cout << "Nothing\n";
#if 0
  {
    vector< std::thread > threads;
    vector< std::promise<int> > promises;
    for ( int i=0; i<NTHREADS; ++i ) {
      std::promise<int>() p;
      threads.emplace_back
	( is_even,i,promises.at(i) );
    }
    for ( auto& t : threads ) 
      t.join();
    for ( auto& p : promises )
      cout << p.get_future().get() << '\n';
    // vector< std::future<int> > results;
    // results.push_back( promises.back().get_future() );
    // for ( auto& r : results )
    //   cout << r.get() << " ";
    cout << '\n';
  }
#endif
  cout << "nothing\n";

  return 0;
}
