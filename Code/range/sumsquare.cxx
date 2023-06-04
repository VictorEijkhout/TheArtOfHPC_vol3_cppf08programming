/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** sumsquare.cxx : C++20 ranges for sum of squares.
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <vector>
using std::vector;

//#include <ranges>
// we need accumulate
#include <range/v3/all.hpp>
#ifdef RANGES_V3_ALL_HPP
namespace rng = ranges;
#else
namespace rng = std::ranges;
#endif

#include <algorithm>
#include <numeric> // for accumulate

int main()
{
  {
    //codesnippet sumsquarer
    vector<float> elements{.5f,1.f,1.5f};
    auto squares =
      rng::views::transform(elements, [] (auto e) { return e*e; } );
    auto sumsq =
      rng::accumulate( squares, 0.f );
    cout << "Sum of squares: " << sumsq << '\n';
    //codesnippet end
  }
  return 0;
}
