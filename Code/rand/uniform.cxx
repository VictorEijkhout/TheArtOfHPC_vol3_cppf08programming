/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** uniform.cxx : trying to demonstrate the difference between
 ****                 two random number generators
 **** DOES NOT WORK
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <functional>
using std::function;
#include <vector>
using std::vector;

#include <random>
// #include "rand.h"

#include "cxxopts.hpp"

int main(int argc,char **argv) {

  cxxopts::Options options("uniform", "Detect uniform random");
  options.add_options()
    ("h,help","usage information")
    ("b,buckets","number of buckets",
     cxxopts::value<int>()->default_value("4096"))
    ("s,samples","number of samples",
     cxxopts::value<int>()->default_value("1000"))
    ;
  auto result = options.parse(argc, argv);
  if (result.count("help")>0) {
    std::cout << options.help() << '\n';
    return 0;
  }
  int nbuckets = result["buckets"].as<int>();
  int nsamples = result["samples"].as<int>();

  for ( auto strategy : {1,2} ) {
    function< int() > random_number;
    std::uniform_int_distribution<> distribution(0,nbuckets-1);
    std::default_random_engine generator;
    if (strategy==1)
      random_number = [nbuckets] () { return rand() % nbuckets; };
    else {
      random_number = [&generator,&distribution] () { return distribution(generator); };
    }
    vector<int> buckets( nbuckets);
    for (int i=0; i<nbuckets*nsamples; i++) {
      int v = random_number();
      buckets[v]++;
    }
    int pos{0},neg{0};
    for_each( buckets.begin(),buckets.end(),
	      [&pos,&neg,nsamples] (int i) {
		int d = i-nsamples;
		if (d>pos) pos = d;
		if (-d>neg) neg = -d;
	      } );
    cout << "Deviation over=" << pos << ", under=" << neg << '\n';
  }

  return 0;
}
