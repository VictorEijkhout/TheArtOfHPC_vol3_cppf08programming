/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** sieve.cxx : Erathosthenes sieve
 ****
 **** teaches : arrays
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int main() {
  int largest;
  cout << "What is the largest number you want to test?" << '\n';
  cin >> largest;

  //examplesnippet primesieve
  vector<int> integers(largest-1);

  for (int i=0; i<largest-1; i++)
    integers[i] = 2+i;

  int starting_point = 0;
  while (starting_point<largest) {
    if (integers[starting_point]>0) {
      int prime = integers[starting_point];
      cout << "Found prime: " << prime << '\n';
      for (int scratch=starting_point; scratch<largest; scratch+=prime)
	integers[scratch] = 0;
    }
    starting_point++;
  }
  //examplesnippet end

  return 0;
}
