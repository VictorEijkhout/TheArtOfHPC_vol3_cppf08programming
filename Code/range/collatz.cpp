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

#include <ranges>
// to<> not yet in gcc12
//#include <range/v3/all.hpp>
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

  auto collatz = [] ( int n ) { if (n%2==0) return n/2; else return 3*n+1; };

  {
    vector<int> v{ 1,2,3,4,5,6 };
    cout << vector_as_string(v) << '\n';

    vector<int> w(v);
    // use either ranges::transform or std::transform
    rng::transform( v.begin(),v.end(), w.begin(),collatz );
    cout << vector_as_string(w) << '\n';

    rng::transform( v,w.begin(),collatz );
    cout << vector_as_string(w) << '\n';

    rng::copy( v | rng::views::transform(collatz), w.begin() );
    cout << vector_as_string(w) << '\n';

    auto wr = v | rng::views::transform(collatz); // | rng::to<vector<int>>;
    for ( auto c : wr ) cout << c << " "; cout << '\n';

  }

  return 0;
}
