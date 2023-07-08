/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** range.cxx : C++20 ranges
 ****
 **** Inspired by https://www.youtube.com/watch?v=d9ToM7sIvq0&t=5s
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <sstream>
using std::stringstream;
#include <string>
using std::string;

#include <algorithm>
using std::transform;
#include <vector>
using std::vector;

//#include <ranges>
// views::sliding & to<> not yet in gcc12
#include <range/v3/all.hpp>
#ifdef RANGES_V3_ALL_HPP
namespace rng = ranges;
#else
namespace rng = std::ranges;
#endif

template< typename T >
string vector_as_string( const vector<T> &v ) {
  stringstream s;
  for ( auto e : v )
    s << e << ", ";
  return s.str();
};

int main()
{

  {
    vector<float> v{ 1,2,3,4,5,6 };
    auto sum = [] ( rng::subrange<vector<float>::iterator> subrang ) {
      auto [ first,tail ] = subrang;
      float
        x = *( subrang.begin() ),
	y = *( subrang.begin()+1 ),
        z = *( subrang.begin()+2 );
      return -x +2*y -z;
    };
    auto w = v
      | rng::views::sliding(3) | rng::views::transform(sum);
    //   | rng::to<vector<float>>;
    // cout << vector_as_string(w) << '\n';
  }

  return 0;
}
