/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** the C++ permutation generator
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;
#include <algorithm>
using std::for_each;

#include <random>

int main() {

  const int N = 30;
  std::random_device r;
  std::default_random_engine generator; // {r()};
  std::uniform_int_distribution<> distribution(0,N-1);

  vector<int> numbers(N);
  for (int i=0; i<N; i++)
    numbers[i] = i;

  for (int pass=0; pass<N; pass++) {
    int
      i = distribution(generator),
      j = distribution(generator);
    int t = numbers[i]; numbers[i] = numbers[j]; numbers[j] = t;
  }

  vector<int> check(N,0);
  for (int i=0; i<N; i++) {
    cout << numbers[i] << " ";
    check[i]++;
  }
  cout << '\n';

  bool allone{true};
  std::for_each
    ( check.begin(),check.end(),
      [&allone] (auto e) { allone = allone and e==1; }
      );
  if (allone)
    cout << "Indeed a permutation\n";
  else
    cout << "Note a permutation\n";

  return 0;
}
