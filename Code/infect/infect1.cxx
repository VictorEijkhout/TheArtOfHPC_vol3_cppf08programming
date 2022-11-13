/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** infect1.cxx : multiple persons random infection
 ****               using classes
 ****
 ****************************************************************/

#include <cmath>
#include <iostream>
using std::cin;
using std::cout;
#include <iomanip>
using std::setw;

#include <random>
#include <ctime>
#include <vector>

#include "infect_lib_simple.h"

int main() {

  // initialize random generator
  srand(100*time(NULL)%100);

  int npeople;
  cout << "Size of population? ";
  cin >> npeople;
  cout  << '\n';
  Population population(npeople);

  // set patient zero
  population.random_infection(5,.8f);

  std::vector<int> history;
  int max_infected = 1;
  int step = 1;
  //codesnippet infect1loop
  for ( ; ; step++) {

    int count_infected{0};
    population.update();
    count_infected = population.count_infected();
    cout << "In step " << setw(3) << step
         << " #sick: " << setw(4) << count_infected
         << " : " << population.display() << '\n';
    //cout << "#infected: " << count_infected << '\n';

    if (count_infected==0)
      break;
  }
  cout << "Disease ran its course by step " << step << '\n';
  //codesnippet end

  return 0;
}
