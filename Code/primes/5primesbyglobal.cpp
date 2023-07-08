/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** primesbyfunction.cxx : print a user specified quantity of primes
 **** this builds on primesbyfunction.cxx
 ****
 **** teaches : global variables
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

int numberfound = 0;
int currentnumber = 2;

bool isprime(int number) {
  for (int divisor=2; divisor<number; divisor++) {
    if (number%divisor==0) {
      return false;
    }
  }
  return true;
};
int nextprime() {
  while (!isprime(currentnumber)) {
    currentnumber++;
  }
  numberfound++;
  return currentnumber++;
};

int main() {
  int nprimes;
  cout << "How many primes do you want? " << '\n';
  cin >> nprimes;

  while (numberfound<nprimes) {
    int number = nextprime();
    cout << "Number " << number << " is prime" << '\n';
  }

  return 0;
}
