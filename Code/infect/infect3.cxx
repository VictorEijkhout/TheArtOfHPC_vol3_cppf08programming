/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** infect3.cxx : testing reproduction number in 1d
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

#include "infect_lib.h"

int main( int argc,char **argv) {
  
  // https://github.com/jarro2783/cxxopts
  cxxopts::Options options("cachesize", "Detect cache sizes");
  options.add_options()
    ("h,help","usage information")
    ("b,batch","batch mode: no prompt",
     cxxopts::value<bool>()->default_value("false"))
    ("i,initial","number of initially infected",
     cxxopts::value<int>()->default_value("1"))
    ("c,contact","number of daily contacts",
     cxxopts::value<int>()->default_value("5"))
    ("l,locality","locality dropoff",
     cxxopts::value<int>()->default_value("0"))
    ("n,population","size of population",
     cxxopts::value<int>()->default_value("10000"))
    ("p,probability","probability of transfer (0-100)",
     cxxopts::value<int>()->default_value("50"))
    ("v,vaccin","percentage vaccinated",
     cxxopts::value<int>()->default_value("80"))
    ;

  int
    initial_infect{-1}, npeople{-1}, ncontact{-1}, ivaccin{-1}, locality{-1},
    iprobable{-1};
  bool
    display{false},batch{false};
  try { 
    auto result = options.parse(argc, argv);
    if (result.count("help")>0) {
      cout << "Usage!" << '\n';
      return 0;
    }
    batch          = result["batch"].as<bool>();
    initial_infect = result["initial"].as<int>();
    npeople        = result["population"].as<int>();
    ncontact       = result["contact"].as<int>();
    iprobable      = result["probability"].as<int>();
    ivaccin        = result["vaccin"].as<int>();
    locality       = result["locality"].as<int>();
  } catch (cxxopts::option_not_present_exception x) {
    cout << "Requesting unknown option <<" << x.what() << ">>\n";
    exit(1);
  }

#if 0
  for (int iarg=1; iarg<argc; ) {
    if (!strcmp(argv[iarg],"-h"))
      cout << "Usage: " << argv[0]
	   << " [ -d ] [ -b : batch, no prompt ] [ -c ncontact ] [ -i initial infect ]"
	   << " [ -l 1/2/3 ]"
	   << '\n';
    else if (!strcmp(argv[iarg],"-d"))
      display = true;
    else if (!strcmp(argv[iarg],"-b"))
      batch = true;
    else if (!strcmp(argv[iarg],"-i"))
      initial_infect = atoi(argv[++iarg]);
    /* locality simulation */
    else if (!strcmp(argv[iarg],"-l"))
      locality = atoi(argv[++iarg]);
    /* population size */
    else if (!strcmp(argv[iarg],"-n"))
      npeople = atoi(argv[++iarg]);
    /* number of contacts per day */
    else if (!strcmp(argv[iarg],"-c"))
      ncontact = atoi(argv[++iarg]);
    /* probability percentage of transmission on contact */
    else if (!strcmp(argv[iarg],"-p"))
      iprobable = atoi(argv[++iarg]);
    /* vaccination percentage */
    else if (!strcmp(argv[iarg],"-v"))
      ivaccin = atoi(argv[++iarg]);
    iarg++;
  }
#endif

  /*
   * 1. Population size
   */
  if (npeople<0) {
    if (!batch) cout << "Size of population?";
    cin >> npeople;
    if (!batch) cout  << '\n';
  }
  Population population(npeople,ncontact);
  population.set_locality(locality);

  /*
   * 2. Percentage vaccinated
   */
  if (ivaccin<0) {
    if (!batch) cout << "Innocalation percentage (0-100) ?";
    cin >> ivaccin;
    if (!batch) cout << '\n';
  }
  population.inoculate(0.01 * ivaccin);

  /*
   * 3. Probability of transfer
   */
  if (iprobable<0) {
    if (!batch) cout << "Probability of disease transfer (0-100) ? ";
    cin >> iprobable;
    if (!batch) cout << '\n';
  }
  Disease fever(.01 * iprobable);
  
  // set patient zero
  population.random_infection(fever);

  int n_susceptible = population.count_susceptible();

  // count how many people can get infected
  std::vector<int> history;
  int max_infected = population.count_infected(), max_step=0;
  history.push_back(1);

  for ( ; ; max_step++) {

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

  cout << "Population: " << population.size() << " "
       << "probability " << setw(5) << setprecision(3) << fever.probability() << " "
       << "contacts_per_day " << setw(2) << ncontact << " "
       << "max_infected: " << setw(4) << max_infected << " "
       << "total_sick: " << setw(4) << population.recovered() << " "
       << "disease_run " << setw(3) << max_step << " "
       << '\n';
  int n_unaffected = population.count_susceptible();
  // cout << "susceptible people unaffected: " << n_unaffected
  //      << " out of " << n_susceptible << '\n';
  
  return 0;
}
