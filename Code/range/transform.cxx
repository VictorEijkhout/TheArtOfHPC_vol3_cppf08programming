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

#include <vector>
using std::vector;

#include <range/v3/all.hpp>

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
    std::transform( v.begin(),v.end(), w.begin(),collatz );
    cout << vector_as_string(w) << '\n';

    ranges::transform( v,w.begin(),collatz );
    cout << vector_as_string(w) << '\n';

    ranges::copy( v | ranges::views::transform(collatz), w.begin() );
    cout << vector_as_string(w) << '\n';

    w = v | ranges::views::transform(collatz) | ranges::to<vector<int>>;
    cout << vector_as_string(w) << '\n';
  }

  {
    vector<float> v{ 1,2,3,4,5,6 };
    auto sum = [] ( ranges::subrange<vector<float>::iterator> subrang ) {
      auto [ first,tail ] = subrang;
      float
        x = *( subrang.begin() ),
	y = *( subrang.begin()+1 ),
        z = *( subrang.begin()+2 );
      return -x +2*y -z;
    };
    auto w = v
      | ranges::views::sliding(3) | ranges::views::transform(sum)
      | ranges::to<vector<float>>;
    cout << vector_as_string(w) << '\n';
  }

    // cout << "Original vector: "
    //      << vector_as_string(v) << '\n';

  return 0;
}
