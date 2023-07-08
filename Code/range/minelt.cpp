/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** minelt.cxx : min_element through iterators and ranges
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <vector>
using std::vector;

#include <ranges>
//#include <range/v3/all.hpp>
#ifdef RANGES_V3_ALL_HPP
namespace rng = ranges;
#else
namespace rng = std::ranges;
#endif

#include <algorithm>

int main()
{
  {
    //codesnippet minelement
    vector<float> elements{.5f,1.f,1.5f};
    auto min_iter = std::min_element
      (elements.begin(),elements.end());
    cout << "Min: " << *min_iter << '\n';
    //codesnippet end
  }
  {
    //codesnippet minelementr
    vector<float> elements{.5f,1.f,1.5f};
    auto min_iter =
      rng::min_element(elements);
    cout << "Min: " << *min_iter << '\n';
    //codesnippet end
  }
  return 0;
}
