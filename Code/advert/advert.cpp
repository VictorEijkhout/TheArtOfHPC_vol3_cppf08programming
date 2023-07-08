/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** advert.cxx : initial attempt branding project
 ****
 **** CAN'T GET THIS TO WORK. LET'S GIVE UP ON IT.
 ****
 ****************************************************************/

#include <cmath>
#include <random>

#include <iostream>
#include <sstream>
using std::cout, std::iostream, std::stringstream;

#include <string>
using std::string;
#include <tuple>
using std::pair;
#include <vector>
using std::vector;

#include <cassert>

float price_sensitivity() { return 1.f; };
float global_unit_price() { return 1.f; };
// float average_advertising_budget() { return 1.f; };
float free_demand( float budget_i,float budget_avg,bool trace=false ) {
  assert(budget_i>=0); assert(budget_avg>=0);
  float computed_demand = budget_i - budget_avg;
  auto demand_floor = .1f*budget_avg, demand_ceiling = 10.f*budget_avg;
  if (trace)
    cout << "computed demand: " << computed_demand
	 << " from budget " << budget_i
	 << " vs avg " << budget_avg
	 << " (" << demand_floor << "," << demand_ceiling << ")\n";
  if (computed_demand<demand_floor) {
    return demand_floor;
  } else if (computed_demand>demand_ceiling) {
    return demand_ceiling;
  } else {
    return computed_demand;
  }
};

class Brand {
private:
  int brand_number;
  float _advertising_budget{1};
  int units_produced{1};
public:
  // default constructor
  Brand() { brand_number = _number_of_brands++; };
  // constructor from parameters
  Brand( int units,float budget )
    : _advertising_budget(budget),
      units_produced(units) {
    brand_number = _number_of_brands++;
    while (profit(_advertising_budget)<1)
      units_produced++;
  };
  string as_string() const {
    stringstream ss;
    ss << "Brand " << brand_number
       << " produces " << units_produced << " units"
       << " with advertising budget " << _advertising_budget;
    return ss.str();
  };
  float unit_price() const { return global_unit_price(); };
  float production_cost() const {
    return static_cast<float>( units_produced ) * unit_price(); };
  float advertising_budget() const { return _advertising_budget; };
  float cost() const { return production_cost() + advertising_budget(); };
  float profit(float avg_advertising_budget,bool trace=false) const {
    auto dmd = 
      free_demand(_advertising_budget,avg_advertising_budget,trace);
    // - price_sensitivity() * unit_price();
    auto rev =
      dmd * unit_price();
    return rev - cost();
  };
  // adjust parameters:
  void produce(int units) { units_produced = units; };
  void advertise(float budget) { _advertising_budget = budget; };
  // optimization
  pair<float,float> optimize_budget(float avg_advertising_budget) const;

private:
  static inline int _number_of_brands{1};
public:
  static int number_of_brands() { return _number_of_brands-1; };
};

iostream& operator<<( const Brand& b,iostream &ios ) {
  ios << b.as_string();
  return ios;
};

int main( /* int argc,char **argv */ ) {

  const int nbrands = 4;

  vector<Brand> brands;
  for (unsigned ibrand=0; ibrand<nbrands; ibrand++)
    brands.push_back( Brand( 100, 1.5f+static_cast<float>(ibrand) ) );
  cout << "Number of brands: " << Brand::number_of_brands() << '\n';

  for ( int it=0; it<1; it++) { // time steps
    auto avg_advertising_budget = 0.f;
    for ( auto b : brands )
      avg_advertising_budget += b.advertising_budget();
    avg_advertising_budget /= brands.size();
      // accumulate( brands.begin(),brands.end(),0.f,
      // 		  [] ( const Brand& b1, const Brand& b2 ) -> float {
      // 		    return b1.advertising_budget() + b2.advertising_budget();
      // 		  }
      // 		  ) / brands.size();
    vector<float> budgets( brands.size() );
    for (unsigned ibrand=0; ibrand<brands.size(); ibrand++) {
      cout << "Optimize brand " << ibrand << '\n';
      auto [new_budget,new_profit] = brands.at(ibrand).optimize_budget(avg_advertising_budget);
      cout << " new budget " << brands.at(ibrand).advertising_budget()
	   // << " giving profit " << brands.at(ibrand).profit()
	   // << ", setting to " << new_budget
	   << " giving profit " << new_profit
	   << '\n';
    }
  }
  
  return 0;
}

pair<float,float> Brand::optimize_budget(float avg_advertising_budget) const {
  float
    optimal_profit=profit(avg_advertising_budget,true),
    optimal_budget = _advertising_budget;
  for (float try_budget=_advertising_budget/5;
       try_budget<_advertising_budget*5; try_budget += _advertising_budget/4 ) {
    Brand new_and_improved(units_produced,try_budget);
    float new_profit = new_and_improved.profit(avg_advertising_budget);
    cout << "....trying budget " << try_budget << " gives profit " << new_profit << '\n';
    if (new_profit>optimal_profit) {
      optimal_profit = new_profit; optimal_budget = try_budget;
    }
  }
  return {optimal_budget,optimal_profit};
};
