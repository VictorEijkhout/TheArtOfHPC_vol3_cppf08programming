/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** infect0.cxx : single person random infection
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <random>

#include "infect_lib.hpp"

int main() {

  int duration  = 5;

  Person joe;
  Disease flu;
  flu.duration() = 5;

  //codesnippet infectpmain
  for ( int step = 1; ; ++step ) {

    joe.one_more_day();
  //codesnippet end
    float bad_luck = random_percentage();
    if (bad_luck>.95 and joe.is_susceptible())
      joe.infect(flu);

  //codesnippet infectpmain
    cout << "On day " << step << ", Joe is "
         << joe.status_string() << '\n';
    if (joe.is_recovered())
      break;
  }
  //codesnippet end


  return 0;
}
