/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** cutoff.cxx : redistricting exercise with linear districts
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <random>
using std::rand;

#include <vector>
using std::vector;

struct {int splitpoint;int surplus} strategy;

int minority_(vector<int> votes,int current_voter) {
  if (current_voter==0) {
    if (votes[0]==1)
      return 0;
    else
      return 1;
  } else {
    if (votes[0]==1)
      return 0 + minority(votes,current_voter-1);
    else
      return 1 + minority(votes,current_voter-1);
  }
}

float lowest_rule(votes) {
  int split_point;
  return bias(votes,votes.size()-1)
}

int main() {

  // initialize random generator
  srand(time(NULL));
  
  int population_size;
  cout << "Population size? ";
  cin >> population_size;
  cout << '\n';
  float majority_percentage;
  cout << "Majority percentage? ";
  cin >> majority_percentage;
  cout << '\n';

  vector<int> votes(population_size);
  int actual_majority{0};
  for ( auto &v : votes ) {
    if (rand()/float(RAND_MAX)<majority_percentage) {
      v = 1;
      ++actual_majority;
    } else v = 0;
  }
  cout << "Actual majority: " << actual_majority << '\n';
  
  float ruling_fraction;
  ruling_fraction = lowest_rule(votes);
  cout << "Minority rules" << ruling_fraction << '\n';

  return 0;
}
