/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** mutate.cxx : Trying with mutating disease
 ****
 ****************************************************************/

#include <cstring>

#include <iostream>
using std::cin;
using std::cout;

#include <iomanip>
using std::setw;
using std::setprecision;

#include <ctime>
#include <vector>

#include "cxxopts.hpp"

#include "infect_lib.hpp"

int main( int argc,char **argv) {
  
  // https://github.com/jarro2783/cxxopts
  cxxopts::Options options("cachesize", "Detect cache sizes");
  options.add_options()
    ("h,help","usage information")
    // ("b,batch","batch mode: no prompt",
    //  cxxopts::value<bool>()->default_value("false"))
    ("i,initial","number of initially infected",
     cxxopts::value<int>()->default_value("10"))
    ("c,contact","number of daily contacts",
     cxxopts::value<int>()->default_value("5"))
    ("l,locality","locality dropoff",
     cxxopts::value<int>()->default_value("0"))
    ("m,mutation","mutation per this many transmissions, zero for no mutations",
     cxxopts::value<float>()->default_value("0"))
    ("n,population","size of population",
     cxxopts::value<int>()->default_value("10000"))
    ("p,probability","probability of transfer (0-100)",
     cxxopts::value<int>()->default_value("50"))
    ("v,vaccin","percentage vaccinated",
     cxxopts::value<int>()->default_value("80"))
    ("t,trace","trace mode",
     cxxopts::value<bool>()->default_value("false"))
    ;

  int
    n_initial_infected{-1}, npeople{-1}, ncontact{-1}, ivaccin{-1}, locality{-1},
    iprobable{-1};
  bool
    display{false},trace{false};
  try { 
    auto result = options.parse(argc, argv);
    if (result.count("help")>0) {
      cout << options.help() << '\n';
      return 0;
    }
    n_initial_infected = result["initial"].as<int>();
    //    batch          = result["batch"].as<bool>();
    npeople        = result["population"].as<int>();
    ncontact       = result["contact"].as<int>();
    iprobable      = result["probability"].as<int>();
    ivaccin        = result["vaccin"].as<int>();
    locality       = result["locality"].as<int>();
    Disease::mutation_rate  = result["mutation"].as<float>();
    trace          = result["trace"].as<bool>();
  // } catch (cxxopts::option_not_present_exception x) {
  //   cout << "Requesting unknown option <<" << x.what() << ">>\n";
    // exit(1);
  } catch (...) {
    cout << "Error in options processing" << '\n';
    exit(1);
  }

  Population population(npeople,ncontact);
  population.vaccinate(ivaccin);
  population.set_locality(locality);
  Disease fever(.01 * iprobable);
  
  // set patient zero
  population.random_infection(fever,n_initial_infected);

  int n_susceptible = population.count_susceptible();

  // count how many people can get infected
  std::vector<int> history;
  int max_infected = population.count_infected(), max_step=0;
  history.push_back(1);

  for ( ; ; max_step++) {

    if (trace)
      cout << "Day: " << max_step << " "
	   << "variants: " << Disease::variants
	   << '\n';
    int infected{0};
    population.update();
    infected = population.count_infected();
    if (display)
      cout << "In step " << setw(3) << max_step
	   << " #sick: " << setw(4) << infected
	   << " : " << population.display() << '\n';

    history.push_back(infected);
    if (infected>max_infected)
      max_infected = infected;
    
    if (infected==0)
      break;

  }

  int ndigits = [n=population.size(),d=1] () mutable -> int {
    while (n>1) { d+=1 ; n/=10; } return d; }();
  int percentage_sick = 100. * ( population.size()-population.recovered() ) / population.size();
  cout << "Population: "      << population.size() << " "
       << "probability "      << setw(5) << setprecision(3) << fever.probability() << " "
       << "contacts_per_day " << setw(2) << ncontact << " "
       << "vaccinated % "     << setw(3) << ivaccin << " "
       << "max_infected: "    << setw(ndigits) << max_infected << " "
    // << "total % sick: "    << setw(3) << percentage_sick << " "
       << "#days "            << setw(3) << max_step << " "
       << "u rate: "          << Disease::mutation_rate << " "
       << "variants: "        << Disease::variants << " "
       << '\n';
  int n_unaffected = population.count_susceptible();
  // cout << "susceptible people unaffected: " << n_unaffected
  //      << " out of " << n_susceptible << '\n';
  
  return 0;
}
