/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** compare.cxx : C++ spaceship operator
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <iomanip>
using std::boolalpha;
#include <numeric>
using std::accumulate;
#include <array>
using std::array;
#include <vector>
using std::vector;

#include <compare>
class witharray {
private:
  array<int,4> the_array;
public:
  witharray( array<int,4> v )
    : the_array(v) {};
  int size() { return the_array.size(); };
  std::partial_ordering operator<=>( const witharray& other ) const {
    std::strong_ordering c = ( the_array[0]<=>other.the_array[0] );
    for (int id=0; id<4; id++)
      if ( ( the_array[id]<=>other.the_array[id] ) != c )
	return std::partial_ordering::unordered;
    return c;
  };
};

int main() {
  witharray up{ {1,2,3,4} };
  cout << "Size: " << up.size() << '\n';
  witharray low{ {0,1,2,3} };
  cout << "comparison should be true: "
       << boolalpha << (low<up) << '\n';

  return 0;
}
