/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
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

#include <range/v3/all.hpp>
//using namespace ranges;

/*
  Since none of the large standard libraries ship C++ Ranges right now,
  you need to use the range-v3 library if you want to try any of
  this. If you do, you need to replace the std::ranges:: prefixes with
  just ranges:: and any std::views:: prefixes with ranges::views::.
 */

// #include "./range/recursive_range.hpp"

string vector_as_string( const vector<int> &v ) {
  stringstream s;
  for ( auto e : v )
    s << e << ", ";
  return s.str();
};

int main()
{
  using namespace ranges::views;

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
  ranges::sort(ranges::views::drop(v_range, 5));

  {
    vector<int> v{3,1,2,4,5,7,9,11,12,8,10};
    cout << "Original vector: " << vector_as_string(v) << '\n';
    auto v_rev1 = v
      | ranges::to_vector // why?
      | ranges::actions::sort  // drop first element, then sort
      ;
  }

#if 0
  {
    vector<int> v{3,1,2,4,5,7,9,11,12,8,10};
    cout << "Original vector: " << vector_as_string(v) << '\n';
    auto v_rev1 = v
      | ranges::views::drop(1) | ranges::actions::sort  // drop first element, then sort
      | ranges::views::reverse | ranges::views::drop(1) // remove last element
      | ranges::views::reverse | ranges::to_vector     // flip and convert to vector
      ;
    cout << "Not first element, largest removed: " << vector_as_string(v_rev1) << '\n';
  }
#endif

  // auto v_rev2 = v | ranges::views::reverse | ranges::sort | ranges::to_vector;
  // cout << "View reverse sorted: " << vector_as_string(v_rev2) << '\n';

}
