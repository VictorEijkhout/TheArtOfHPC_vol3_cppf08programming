/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** range.cxx : C++20 ranges
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

string vector_as_string( const vector<int> &v ) {
  stringstream s;
  for ( auto e : v )
    s << e << ", ";
  return s.str();
};

int main()
{
  using namespace ranges::views;

  {
    cout << "One" << '\n';
    //codesnippet filtertransform
    vector<int> v{ 1,2,3,4,5,6 };
    cout << "Original vector: "
         << vector_as_string(v) << '\n';
    auto times_two = v
      | transform( [] (int i) { return 2*i; } );
    cout << "Times two: "
         << vector_as_string
              ( times_two | ranges::to_vector )
         << '\n';
    auto over_five = times_two
      | filter( [] (int i) { return i>5; } );
    cout << "Over five: "
         << vector_as_string
              ( over_five | ranges::to_vector )
         << '\n';
    //codesnippet end
    cout << "one" << '\n';
  }

  {
    cout << "Second" << '\n';
    //codesnippet filtertransformpipe
    vector<int> v{ 1,2,3,4,5,6 };
    cout << "Original vector: "
         << vector_as_string(v) << '\n';
    auto times_two_over_five = v
      | transform( [] (int i) { return 2*i; } )
      | filter( [] (int i) { return i>5; } );
    cout << "Times two over five: "
         << vector_as_string
              ( times_two_over_five | ranges::to_vector )
         << '\n';
    //codesnippet end
    cout << "second" << '\n';
  }

  return 0;
}
