/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** manu.cxx : example
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int main() {

  float overall_expectation = 0;
  vector<float> local_value;
  vector<float> ratio_chosen;

  for ( int i=0; i<10; i++ ) {
    local_value.push_back( (1+overall_expectation)/2. );
    ratio_chosen.push_back( 1.-overall_expectation );

    overall_expectation =
      (1-ratio_chosen.back())*overall_expectation
      + ratio_chosen.back() * local_value.back();
    cout << overall_expectation << '\n';

    float expectation_check{0.f};
    // for ( int ii=0; ii<expectation.size(); ii++)
    //   expectation_check += ratio_chosen.at(ii) * local_value.at(ii);
    // cout << "  check: " << expectation_check << '\n';
  }

  return 0;
}
