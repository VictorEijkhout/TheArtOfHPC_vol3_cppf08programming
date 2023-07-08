/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** second.cxx : using chrono seconds
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <iomanip>
using std::boolalpha;
#include <thread>

#include <chrono>
using namespace std::chrono;

int main() {

  //codesnippet clocksleep
  using clock = system_clock;
  clock::time_point  before = clock::now();
  std::this_thread::sleep_for( 1.5s );
  auto after = clock::now();
  cout << "Slept for "
       << duration_cast<milliseconds>(after-before).count()
       << "ms\n";
  //codesnippet end

  return 0;
}
