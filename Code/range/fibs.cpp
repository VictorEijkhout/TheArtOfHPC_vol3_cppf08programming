/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** fibs.cxx : C++20 ranges, some advanced range-v3 stuff
 ****
 **** WHERE DID I GET THAT recursive_range_fn FROM? DOES IT EXIST?
 ****
 ****************************************************************/

#include <iostream>

//#include <ranges>
// we need recursive_range_fn
#include <range/v3/all.hpp>
#ifdef RANGES_V3_ALL_HPP
namespace rng = ranges;
#else
namespace rng = std::ranges;
#endif

int main()
{
  using namespace ranges::views;

  // Define a nullary function fibs that returns an infinite range
  // that generates the Fibonacci sequence.
  rng::ext::recursive_range_fn<int> const fibs
    {[&]{
       return concat(closed_ints(0,1), zip_with(std::plus<int>{}, fibs(), tail(fibs())));
     }};
  
  auto x = take(fibs(), 20);
  ranges::for_each(x, [](int i)
		      {
		      });
}
