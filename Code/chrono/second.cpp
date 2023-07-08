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

#include <chrono>
using namespace std::chrono;

void print_seconds( seconds s ) {
  cout << s.count() << "s\n";
}

void print_milliseconds( milliseconds s ) {
  cout << s.count() << "ms\n";
}

int main() {

  //codesnippet seconddef
  seconds s{3};
  auto t = 4s;
  //codesnippet end
  
  cout << "BasicSeconds\n";
  //codesnippet secondarith
  cout << "This lasts "
       << s.count() << "s" << '\n';
  cout << "This lasts ";
  print_seconds( s+5s );
  auto nine = 3.14*3s;
  cout << nine.count()
       << "s is under 10 sec: "
       << boolalpha << (nine<10s)
       << '\n';
  //codesnippet end
  cout << "basicseconds\n";

  cout << "MilliSeconds\n";
  //codesnippet millisecond
  print_milliseconds( 5s );
  // DOES NOT COMPILE print_seconds( 6ms );
  print_seconds( duration_cast<seconds>(6ms) );
  //codesnippet end
  cout << "milliseconds\n";

  return 0;
}
