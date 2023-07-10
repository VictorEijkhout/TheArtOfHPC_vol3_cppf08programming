/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** memo.cxx : memo'ized calculation
 ****
 ****************************************************************/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

using inttype = unsigned long;

inttype catelan(int n) {
  static vector<inttype> numbers{1};
  if (n<numbers.size()) {
    return numbers[n];
  } else {
    // compute the next number
    inttype sum=0;
    for (int i=0; i<n; ++i)
      sum += catelan(i) * catelan(n-1-i);
    cout << "push c_" << n << " = " << sum << '\n';
    numbers.push_back( sum );
    return numbers.back();
  }
};

int main() {
  //  for ( int c=0; c<25; c++ )
  int c = 25;
  cout << "C_" << c << " = " << catelan(c) << '\n';

  return 0;
}

  
