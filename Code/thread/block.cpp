/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016=2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** block.cxx : illustration of blocking behavior of threads
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <cmath>
#include <thread>

#include <unistd.h>

#include <chrono>

int main() {

  using Clock = std::chrono::high_resolution_clock ;

  //codesnippet waitthreadblock
  auto start_time = Clock::now();
  auto waiting_thread =
    std::thread( []() {
      sleep(1);
    }
      );
  waiting_thread.join();
  auto duration = Clock::now()-start_time;
  //codesnippet end

  auto microsec_duration =
    std::chrono::duration_cast<std::chrono::microseconds>(duration);
  cout << "This took " << 1.e-6 * microsec_duration.count() << " sec" << '\n';

  return 0;
}
