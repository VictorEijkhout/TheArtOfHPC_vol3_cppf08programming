/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** adjacent.cxx : C++23 ranges adjacent view
 ****
 **** WRONG: `adjacent' not present in range-v3
 ****
 ****************************************************************/

#include <iostream>
#include <iomanip>
using std::cout,std::setw,std::fixed;

#include <random>
using std::default_random_engine,std::uniform_real_distribution;

#include <vector>
using std::vector;

#if 0
#include <range/v3/all.hpp>
using namespace ranges;
#else
#include <ranges>
using namespace std::ranges;
#endif

int main()
{

  /*
   * Generate some random array
   */
  vector<float> values(10);
  default_random_engine generator{1};
  uniform_real_distribution<float> random_number(0.f,1.f);
  for ( auto& v : values ) {
    v = random_number(generator);
    cout << fixed << setw(3) << v << " ";
  }

  //codesnippet rangeadj3
  for ( auto [ lt,md,rt ] : values | views::adjacent<3> )
    cout << fixed
	 << setw(3) << lt << ","
	 << setw(3) << md << ","
	 << setw(3) << rt << '\n';
  //codesnippet end
}
