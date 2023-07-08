/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** primes.cxx : print a user specified quantity of primes
 **** this builds on primetest.cxx
 ****
 **** prerequisites : cin/cout, arithmetic
 ****
 **** teaches : for and while loops, break
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

int main() {
  int nprimes;
  cout << "How many primes do you want? " << '\n';
  cin >> nprimes;

  int numberfound = 0;
  int number=2;
  while (numberfound<nprimes) {
    bool isprime = true;
    for (int divisor=2; divisor<number; divisor++)
      if (number%divisor==0) {
	isprime = false;
	break; // without this it prints all primes
      }
    if (isprime) {
      cout << "Number " << number << " is prime" << '\n';
      numberfound++;
    }
    number++;
  }

  return 0;
}
