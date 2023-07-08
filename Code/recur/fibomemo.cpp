/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** fibomemo.cxx : fibonacci with memoization
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <iomanip>
using std::setw;

#include <vector>
using std::vector;

int fibonacci_memoized( vector<int> &values, int top );

//codesnippet fibomemo
int fibonacci(int n) {
  vector<int> fibo_values(n);
  for (int i=0; i<n; i++)
    fibo_values[i] = 0;
  fibonacci_memoized(fibo_values,n-1);
  return fibo_values[n-1];
}
int fibonacci_memoized( vector<int> &values, int top ) {
  int minus1 = top-1, minus2 = top-2;
  if (top<2)
    return 1;
  if (values[minus1]==0)
    values[minus1] = fibonacci_memoized(values,minus1);
  if (values[minus2]==0)
    values[minus2] = fibonacci_memoized(values,minus2);
  values[top] = values[minus1]+values[minus2];
  //cout << "set f(" << top << ") to " << values[top] << '\n';
  return values[top];
}
//codesnippet end

int main() {
  int fibo_n;
  cout << "What number? ";
  cin >> fibo_n;
  cout << "Fibo(" << fibo_n << ") = " << fibonacci(fibo_n) << '\n';

  return 0;
}
