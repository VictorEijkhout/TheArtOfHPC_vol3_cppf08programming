/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** cxxopts.cxx : sophisticated commandline parsing
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include "cxxopts.hpp"

int main(int argc,char **argv) {

  cxxopts::Options options("cxxopts", "Commandline options demo");
  options.add_options()
    ("h,help","usage information")
    ("n,npoints","number of points",
     cxxopts::value<int>()->default_value("37")
     )
    ;
  options.allow_unrecognised_options();

  auto result = options.parse(argc, argv);
  if (result.count("help")>0) {
    std::cout << options.help() << std::endl;
    return 0;
  }
  int number_of_points = result["npoints"].as<int>();
  cout << "Using number of points: " << number_of_points << "\n";

  return 0;
}
