/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** interaction.cxx : explore interaction modes for persons
 ****
 ****************************************************************/

#include <cmath>

#include <iostream>
using std::cin, std::cout;
#include <iomanip>
using std::setw,std::boolalpha;

#include <tuple>
using std::tuple;

#include "infect_lib.hpp"

int main() {

  for ( auto [p,days,state] : {
      tuple<float,int,bool>{1.f,1,true},
      {.5f,20,true},
      {0.f,20,false} } ) {
    //codesnippet fluspecs
    Disease flu;
    flu.duration() = 20;
    flu.transfer_probability() = p;    
    //codesnippet end
    //codesnippet flutransfer
    Person infected,healthy;
    infected.infect(flu);
    //codesnippet end
    cout << "healthy: " << boolalpha << healthy.is_healthy() << '\n';
    for ( int day=0; day<days; ++day )
    //codesnippet flutransfer
      healthy.touch(infected);
    //codesnippet end
    auto sick = healthy.is_sick();
    cout << "Days: " << days
	 << " p= " << p
	 << " sick state s/b " << boolalpha << state
	 << " sick state is " << boolalpha << sick
	 << '\n';
  }
    
  return 0;
}
