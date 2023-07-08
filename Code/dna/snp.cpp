/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** snp.cxx : reading a SNP json
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <fstream>
using std::ifstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <map>
using std::map;
using std::make_pair;

#include <chrono>

/*
 * specific for this exercise
 */
#include <nlohmann/json.hpp>
using json = nlohmann::json;

int main() {

  ifstream snp_file("snpedia-1.json");
  json snp_data = json::parse(snp_file);

  for ( auto [key,value] : snp_data.items() )
    cout << "json key: " << key << '\n';
  auto query = snp_data["query"]["categorymembers"];
  for ( auto [key,value] : query.items() )
    cout << "query field: " << key << '\n';

  return 0;
}
