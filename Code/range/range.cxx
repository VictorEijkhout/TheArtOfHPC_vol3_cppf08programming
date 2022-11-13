/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** range.cxx : C++20 ranges through range lib
 ****
 ****************************************************************/

#include <iostream>
#include <range/v3/all.hpp>
// #include "./range/recursive_range.hpp"

int main()
{
  using namespace ranges::views;

  // Define a nullary function fibs that returns an infinite range
  // that generates the Fibonacci sequence.
  ranges::ext::recursive_range_fn<int> const fibs
    {[&]{
       return concat(closed_ints(0,1), zip_with(std::plus<int>{}, fibs(), tail(fibs())));
     }};
  
  auto x = take(fibs(), 20);
  ranges::for_each(x, [](int i)
		      {
		      });
}
