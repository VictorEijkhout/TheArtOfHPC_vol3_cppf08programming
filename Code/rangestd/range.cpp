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
#include <vector>
using std::vector;
#include <tuple>
using std::pair;

#include <algorithm>
#include <ranges>

vector<int> generate_data() { return {2,3,4,5,6,7}; };

int main()
{

  int count;
  count = 0;
  std::ranges::for_each
    ( generate_data(),
      [&count] (int i) { count += (i<5); }
      );
  cout << "Under five: " << count << '\n';

  count = 0;
  std::ranges::for_each
    ( generate_data() | std::ranges::views::drop(1),
      [&count] (int i) { count += (i<5); }
      );
  cout << "after dropping the first: " << count << '\n';

  count = 0;
  for ( const auto& e : generate_data() | std::ranges::views::drop(1) )
    count += (e<5);
  cout << "same, range looped: " << count << '\n';
  
  auto enumerate = [cnt=0] (int i) mutable { return pair<int,int>{cnt++,i}; };
  for ( auto [i,e] : generate_data() | std::ranges::views::transform( enumerate ) )
    cout << i << ":" << e << '\n';

  return 0;
}
