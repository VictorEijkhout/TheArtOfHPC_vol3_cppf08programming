/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** count.cxx : preliminary exercise for redistricting
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <random>
using std::rand;

#include <vector>
using std::vector;

int minority_counted(vector<int> votes,int current_voter) {
  if (current_voter==0) {
    if (votes[0]==1)
      return 0;
    else
      return 1;
  } else {
    if (votes[current_voter]==1)
      return 0 + minority_counted(votes,current_voter-1);
    else
      return 1 + minority_counted(votes,current_voter-1);
  }
}

float minority_fraction(vector<int> votes) {
  int count = minority_counted(votes,votes.size()-1);
  cout << ".. counted: " << count << '\n';
  return float(count)/votes.size();
}

int main() {

  // initialize random generator
  srand(time(NULL));
  
  int population_size;
  cout << "Population size? ";
  cin >> population_size;
  cout << '\n';
  float majority_fraction;
  cout << "Majority fraction? ";
  cin >> majority_fraction;
  cout << '\n';

  vector<int> votes(population_size);
  int actual_majority{0};
  for ( auto &v : votes ) {
    if (rand()/float(RAND_MAX)<majority_fraction) {
      v = 1;
      ++actual_majority;
    } else v = 0;
  }
  cout << "Actual majority: " << actual_majority << '\n';
  
  float minority_fraction_measured;
  minority_fraction_measured = minority_fraction(votes);
  cout << "Minority rules" << minority_fraction_measured << '\n';

  return 0;
}
