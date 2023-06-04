/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** sort.cxx : sorting
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <sstream>
using std::stringstream;
#include <string>
using std::string;

#include <vector>
using std::vector;

//#include <ranges>
// we need zip
#include <range/v3/all.hpp>
#ifdef RANGES_V3_ALL_HPP
namespace rng = ranges;
#else
namespace rng = std::ranges;
#endif

string vector_as_string( const vector<int> &v ) {
  stringstream s;
  for ( auto e : v )
    s << e << ", ";
  return s.str();
};

int main()
{

  cout << "ItSort\n";
  //codesnippet iteratorsort
  vector<int> v{3,1,2,4,5,7,9,11,12,8,10};
  cout << "Original vector: " << vector_as_string(v) << '\n';

  auto v_std(v);
  std::sort( v_std.begin(),v_std.begin()+5 );
  cout << "Five elements sorts: " << vector_as_string(v_std) << '\n';
  //codesnippet end
  cout << "itsort\n";

  auto v_range(v);
  rng::sort(rng::views::drop(v_range, 5));

  {
    vector<int> v{3,1,2,4,5,7,9,11,12,8,10};
    cout << "Original vector: " << vector_as_string(v) << '\n';
    auto v_rev1 = v
      | rng::to_vector // why?
      | rng::actions::sort  // drop first element, then sort
      ;
  }

#if 0
  {
    vector<int> v{3,1,2,4,5,7,9,11,12,8,10};
    cout << "Original vector: " << vector_as_string(v) << '\n';
    auto v_rev1 = v
      | rng::views::drop(1) | rng::actions::sort  // drop first element, then sort
      | rng::views::reverse | rng::views::drop(1) // remove last element
      | rng::views::reverse | rng::to_vector     // flip and convert to vector
      ;
    cout << "Not first element, largest removed: " << vector_as_string(v_rev1) << '\n';
  }
#endif

  // auto v_rev2 = v | rng::views::reverse | rng::sort | rng::to_vector;
  // cout << "View reverse sorted: " << vector_as_string(v_rev2) << '\n';

}
