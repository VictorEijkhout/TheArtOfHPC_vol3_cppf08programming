/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016=2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** promise.cxx : illustration of promises and futures
 ****
 **** https://stackoverflow.com/questions/12620186/futures-vs-promises
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <sstream>
using std::stringstream;

#include <chrono>
#include <unistd.h>
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
    //codesnippet cpppromise
    auto promise = std::promise<std::string>();
    auto producer = std::thread
      ( [&promise] { promise.set_value("Hello World"); } );

    auto future = promise.get_future();

    auto consumer = std::thread
      ( [&future] { std::cout << future.get() << '\n'; } );

    producer.join(); consumer.join();
    //codesnippet end
  }
  cout << "single\n";

  cout << "Timeout\n";
  {
    auto promise = std::promise<std::string>();
    auto producer = std::thread
      ( [&promise] {
        cout << "Sleep 5 before setting promise\n";
        sleep(5);
        promise.set_value("Hello World");
      } );

    auto future = promise.get_future();

    //codesnippet cpppromisewait
    auto consumer = std::thread
      ( [&future] {
        std::chrono::milliseconds span (1000);
        cout << "Wait for future to get:\n" << std::flush;
        while (future.wait_for(span)==std::future_status::timeout)
          std::cout << " ." << std::flush;
        std::cout
          << " " << future.get() << '\n';
      } );
    //codesnippet end

    producer.join(); consumer.join();
  }
  cout << "timeout\n";

  cout << "Vector\n";
  {
    //codesnippet cpppromisevec
    vector< std::thread > producers,consumers;
    vector< std::promise<string> > promises;

    for ( int i=0; i<4; ++i ) {

      promises.push_back(  std::promise<string>() );
      producers.push_back
        ( std::thread
          ( [ i,&promises ] {
            stringstream ss;
            ss << "Hello world " << i << ".";
            promises.at(i).set_value(ss.str());
          } ) );

      consumers.push_back
        ( std::thread
          ( [ i,&promises ] {
            std::cout << promises.at(i).get_future().get() << '\n';
          } ) );
    }

    for ( auto& p : producers ) p.join();
    for ( auto& c : consumers ) c.join();
    //codesnippet end

  }
  cout << "vector\n";

  return 0;
}
