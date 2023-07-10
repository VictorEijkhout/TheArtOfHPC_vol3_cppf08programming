/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016=2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** async.cxx : illustration of async
 ****
 **** https://stackoverflow.com/questions/12620186/futures-vs-promises
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <sstream>
using std::stringstream;

#include <string>
using std::string;
#include <vector>
using std::vector;

#include <thread>
#include <future>

#ifndef NTHREADS
#define NTHREADS 5
#endif

int main() {

  cout << "Single\n";
  {
    //codesnippet cppasyncone
    std::future<string> fut_str = std::async
      ( [] () -> string { return "Hello world"; } );
    auto result_str = fut_str.get();
    cout << result_str << '\n';
    //codesnippet end
  }
  cout << "single\n";

  cout << "Vector\n";
  {
    //codesnippet cppasyncvec
    vector< std::future<string> > futures;
    for ( int ithread=0; ithread<NTHREADS; ++ithread ) {
      futures.push_back
        ( std::async
	  ( [ithread] () ->string {
            stringstream ss;
            ss << "Hello world " << ithread;
            return ss.str();
          } ) );
    }
    for ( int ithread=0; ithread<NTHREADS; ++ithread ) {
      cout << futures.at(ithread).get() << '\n';
    }
    //codesnippet end
  }
  cout << "vector\n";

  return 0;
}
