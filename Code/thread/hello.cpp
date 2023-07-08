/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** hello.cxx : hello world with threads
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <chrono>
#include <vector>
using std::vector;

#include <thread>

void hello_n( int n ) {
  cout << "Hello " << n << '\n';
}

#ifndef NTHREADS
#define NTHREADS 5
#endif

int main() {

  using myclock = std::chrono::steady_clock ;

  cout << "AllTogether\n";
  {
    //codesnippet threadsmess
    vector< std::thread > threads;
    for ( int i=0; i<NTHREADS-1; i++ ) {
      threads.push_back
        ( std::thread(hello_n,i) );
    }
    threads.emplace_back
      ( hello_n,NTHREADS-1 );
    for ( auto& t : threads ) 
      t.join();
    //codesnippet end
  }
  cout << "alltogether\n";

  cout << "Orderly\n";
  {
    vector< std::thread > threads;
    for ( int i=0; i<NTHREADS; i++ ) {
      //codesnippet threadsnice
      threads.push_back
        ( std::thread
          ( /* function: */
            [] (int i ) {
              std::chrono::seconds wait(i);
              std::this_thread::sleep_for(wait);
              hello_n(i); },
            /* argument: */
            i
            )
          );
      //codesnippet end
    }
    for ( auto& t : threads ) 
      t.join();
  }
  cout << "orderly\n";

  
  return 0;
}
