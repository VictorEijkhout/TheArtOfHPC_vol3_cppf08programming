/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** catelist.cxx : construct all partitionings
 **** UNFINISHED
 ****
 ****************************************************************/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

using elttype = vector<int>;
using cattype = vector<elttype>;

// concatenate Catelan lists
auto operator+(cattype c1,cattype c2) {
  cattype sum;
  sum.insert(sum.end(),c1.begin(),c1.end());
  sum.insert(sum.end(),c2.begin(),c2.end());
  return sum;
};

// combine two partitionings
auto operator *(cattype x,cattype y) {
  cattype combo;
  for ( auto xx : x )
    for ( auto yy : y )
      combo.push_back( xx*yy );
  return combo;
};

cattype catelan(int n) {
  static vector<cattype> numbers{ cattype{elttype{}} };
  if (n<numbers.size()) {
    return numbers[n];
  } else {
    // compute the next number
    elttype sum=cattype;
    for (int i=0; i<n; ++i) {
      auto c1 = catelan(i);
      auto c2 = catelan(n-1-i);
      sum += c1 * c2;
      cout << "push c_" << n << " = " << sum << '\n';
      numbers.push_back( sum );
      return numbers.back();
    }
  };
};

int main() {
  //  for ( int c=0; c<25; c++ )
  int c = 15;
  catelan(c);

  return 0;
}

  
