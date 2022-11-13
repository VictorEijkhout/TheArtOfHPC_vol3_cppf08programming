/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** sumsquare.cxx : C++20 ranges for sum of squares.
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <vector>
using std::vector;

#include <ranges>
#include <algorithm>
#include <numeric> // for accumulate

int main()
{
  {
    //codesnippet sumsquarer
    vector<float> elements{.5f,1.f,1.5f};
    namespace rng = std::ranges;
    namespace vw = std::views;
    auto square_view = vw::transform
      (elements, [] (auto e) { return e*e; } );
    auto sumsq = std::accumulate
      (square_view.begin(),square_view.end(),0.f);
    cout << "Sum of squares: " << sumsq << '\n';
    //codesnippet end
  }
  return 0;
}
