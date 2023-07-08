/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
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
#include <string>
using std::string;

#include "cxxopts.hpp"

#include "infect_lib.hpp"

int main( int argc,char **argv) {
  
  // https://github.com/jarro2783/cxxopts
  cxxopts::Options options("pandemic", "Simulate a pandemic");
  options.add_options()
    ("h,help","usage information")
    ("i,initial","number of initially infected",
     cxxopts::value<int>()->default_value("1"))
    ("c,contact","number of daily contacts",
     cxxopts::value<int>()->default_value("5"))
    ("d,display","display each time step",
     cxxopts::value<bool>()->default_value("false"))
    ("l,locality","locality dropoff",
     cxxopts::value<int>()->default_value("0"))
    ("n,population","size of population",
     cxxopts::value<int>()->default_value("10000"))
    ("p,probability","probability of transfer (0-100)",
     cxxopts::value<int>()->default_value("50"))
    ("t,transmission","0=none 1=neighbor 2=random 3=local",
     cxxopts::value<int>()->default_value("0"))
    ("v,vaccin","percentage vaccinated",
     cxxopts::value<int>()->default_value("0"))
    ;

  auto result =
    [argc,argv,&options] () {
      try {
	return options.parse(argc, argv);
      } catch (cxxopts::exceptions::exception /* option_not_present_exception*/ x) {
	cout << "Requesting unknown option <<" << x.what() << ">>\n";
	exit(1);
      }
    }();
	
  if (result.count("help")>0) {
    cout << options.help() << '\n';
    return 0;
  }

  /*
   * Trace
   */
  bool display = result["display"].as<bool>();

  /*
   * Set up the disease
   */
  Disease fever;
  {
    int iprobable = result["probability"].as<int>();
    fever.transfer_probability() = .01 * iprobable;
  }

  /*
   * Set up the population
   */
  int
    npeople        = result["population"].as<int>(),
    ncontact       = result["contact"].as<int>();
  Population population(npeople,ncontact);

  {
    int transmission = result["transmission"].as<int>();
    population.transmission() =
      [transmission] () {
	switch (transmission) {
	case 1 : return transmission_scheme::neighbor;
	case 2 : return transmission_scheme::random;
	case 3 : return transmission_scheme::local;
	} return transmission_scheme::none;
      }();
  
    if (transmission==3) {
      int locality = result["locality"].as<int>();
    }
  }

  /*
   * Set up infection and spread
   */
  int pvaccin{0};
  {
    pvaccin = result["vaccin"].as<int>();
    population.random_vaccination
      ( [pvaccin,s=population.size()] () -> long int {
	if (pvaccin==100) return s;
	else return static_cast<long int>( .01*s*pvaccin );
      }() );

    int initial_infect = result["initial"].as<int>();
    if (display)
      cout << "Infecting: " << initial_infect << '\n';
    //codesnippet popinitinfect
    population.random_infection(fever,initial_infect);
    //codesnippet end

    if (display) {
      cout << "Initial configuration:\n";
      cout << population.display() << '\n';
    }
  }

  int n_susceptible = population.count_susceptible();

  // count how many people can get infected
  std::vector<int> history;
  int max_infected = population.count_infected(), max_step=0;
  history.push_back(1);

  try {
    for ( ; ; max_step++) {

      int infected{0};
      try {
	population.one_more_day();
      } catch ( string e ) {
	cout << "Update error: " << e << '\n';
	return 1;
      }
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
  } catch (...) {
    // cout << "Exception thrown for\n";
    // for ( int iarg=0; iarg<argc; iarg )
    //   cout << argv[iarg] << " ";
    // cout << '\n';
  }

  cout << "Population: " << population.size() << " "
       << "probability " << setw(5) << setprecision(3) << fever.transfer_probability() << " "
       << "percentage_vaccinated: " << pvaccin << " "
       << "contacts_per_day " << setw(2) << ncontact << " "
       << "max_infected: " << setw(4) << max_infected << " "
       << "total_sick: " << setw(4) << population.count_recovered() << " "
       << "disease_run " << setw(3) << max_step << " "
       << '\n';
  int n_unaffected = population.count_susceptible();
  // cout << "susceptible people unaffected: " << n_unaffected
  //      << " out of " << n_susceptible << '\n';
  
  return 0;
}
