/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** cobbler.cxx : how many cobblers are there?
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

int main() {

  float npersons = 200.e6; // the US of A
  float nrepairs_per_year = npersons;
  float avg_time_per_repair = .5; // measured in hours
  float material_cost_per_repair = 3.5; 
  float hourly_wages = 25;
  float desired_yearly_income = 60.e3;

  float income_per_repair = hourly_wages * avg_time_per_repair;

  // How much does repair cost the customer?
  float cost_per_repair = material_cost_per_repair + income_per_repair;
  cout << "The customer pays " << cost_per_repair << " per repair" << '\n';

  // How much money is there to go around?
  float total_money_spent_on_repair = nrepairs_per_year * income_per_repair;
  int ncobblers = total_money_spent_on_repair / desired_yearly_income;
  cout << "The economy can sustain " << ncobblers << " cobblers" << '\n';
  
  // How many new cobblers per year?
  int working_years = 40;
  int new_cobblers_per_year = ncobblers / working_years;
  cout << "We need " << new_cobblers_per_year << " new cobblers per year" << '\n';
  
  return 0;
}
