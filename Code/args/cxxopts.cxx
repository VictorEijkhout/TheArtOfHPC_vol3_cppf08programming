/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** cxxopts.cxx : sophisticated commandline parsing
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

#include <string>
using std::string;
#include <vector>
using std::vector;

#include "cxxopts.hpp"

int main(int argc,char **argv) {

  //codesnippet cxxoptdefine
  // in the main program:
  cxxopts::Options options
    ("cxxopts", "Commandline options demo");
  //codesnippet end
  //codesnippet cxxopthelp
  options.add_options()
    ("h,help","usage information")
    ;
  //codesnippet end
  //codesnippet cxxoptoptions
  // define `-n 567' option:
  options.add_options()
    ("n,ntimes","number of times",
     cxxopts::value<int>()->default_value("37")
     )
    ;
  //codesnippet end

  //codesnippet cxxoptarray
  //define `-a 1,2,5,7' option:
  options.add_options()
    ("a,array","array of values",
     cxxopts::value< vector<int> >()->default_value("1,2,3")
     )
    ;
  //codesnippet end

  //codesnippet cxxoptarguments
  // define `positional argument' option:
  options.add_options()
    ("keyword","whatever keyword",
     cxxopts::value<string>())
    ;
  options.parse_positional({"keyword"});
  //codesnippet end

  //codesnippet cxxopthelp
  auto result = options.parse(argc, argv);
  if (result.count("help")>0) {
    cout << options.help() << '\n';
    return 0;
  }
  //codesnippet end

  //codesnippet cxxoptoptions
  // read out `-n' option and use:
  auto number_of_times = result["ntimes"].as<int>();
  cout << "Using number of times: " << number_of_times << '\n';
  //codesnippet end

  //codesnippet cxxoptarray
  auto array = result["array"].as<vector<int>>();
  cout << "Array: " ;
  for ( auto a : array ) cout << a << ", ";
  cout << '\n';
  //codesnippet end


  //codesnippet cxxoptarguments
  // read out keyword option and use:
  auto keyword = result["keyword"].as<string>();
  cout << "Found keyword: " << keyword << '\n';
  //codesnippet end

  return 0;
}
