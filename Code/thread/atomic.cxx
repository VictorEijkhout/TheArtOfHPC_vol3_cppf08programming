/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** atomic.cxx : illustration of blocking behavior of threads
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <cmath>

#include <unistd.h>
#include <chrono>

#include <thread>
#include <atomic>

int main() {

  using myclock = std::chrono::steady_clock ;

  //codesnippet threadatomicvar
  auto start_time = myclock::now();
  auto deadline = myclock::now() + std::chrono::seconds(1);
  std::atomic<int> counter{0};
  auto add_thread =
    std::thread( [&counter,deadline]() {
      while (myclock::now()<deadline)
	printf("Thread: %d\n",++counter);
    }
      );
  while (myclock::now()<deadline)
    printf("Main: %d\n",++counter);
  add_thread.join();
  cout << "Final value: " << counter << '\n';
  //codesnippet end

  auto duration = myclock::now()-start_time;
  auto microsec_duration =
    std::chrono::duration_cast<std::chrono::microseconds>(duration);
  cout << "Runtime: " << 1.e-6 * microsec_duration.count() << " sec" << '\n';

  return 0;
}
