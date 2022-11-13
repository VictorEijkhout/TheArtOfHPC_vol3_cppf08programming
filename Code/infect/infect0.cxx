/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** infect0.cxx : single person random infection
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include "infect_lib.h"

int main() {

  int duration  = 5;

  srand(time(NULL));

  //codesnippet infect0
  Person joe;

  int step = 1;
  for ( ; ; step++) {

    joe.update();
    float bad_luck = (float) rand()/(float)RAND_MAX;
    if (bad_luck>.95)
      joe.infect(5);

    cout << "On day " << step << ", Joe is "
         << joe.status_string() << '\n';
    if (joe.is_stable())
      break;
  }
  //codesnippet end

  cout << "Patient recovered in step " << step << '\n';

  return 0;
}
