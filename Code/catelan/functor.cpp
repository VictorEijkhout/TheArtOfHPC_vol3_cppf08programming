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

class catelan {
private:
  static inline vector<inttype> numbers;
  void compute_cn( int n ) {
    if (n<numbers.size()) {
      // has already been computed
      return;
    } else if (n>numbers.size()) {
      // fill in the missing ones
      for (int c=0; c<n; ++c )
	compute_cn(c);
    } else if (n==numbers.size()) {
      // compute the next number
      inttype sum=0;
      if (n==0) sum=1;
      else {
	for (int i=0; i<n; ++i)
	  sum += numbers[i] * numbers[n-1-i];
      }
      // cout << "push c_" << n << " = " << sum << '\n';
      numbers.push_back( sum );
    }
  };
public:
  catelan( int c ) { compute_cn(c); };
  inttype value() { return numbers.back(); };
};

int main() {
  //  for ( int c=0; c<25; ++c )
  int c = 25;
  cout << "C_" << c << " = " << catelan(c).value() << '\n';

  return 0;
}

  
