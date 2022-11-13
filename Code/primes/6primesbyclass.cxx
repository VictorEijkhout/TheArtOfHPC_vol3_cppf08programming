/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** primesbyfunction.cxx : print a user specified quantity of primes
 **** this builds on primesbyglobal.cxx
 ****
 **** teaches: classes with member functions and encapsulated variables
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

class primegenerator {
private:
  int numberfound{0};
  int currentnumber{2};
public:
  primegenerator() {};
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
  int number_of_primes_found() {
    return numberfound;
  };
};

int main() {
  int nprimes;
  cout << "How many primes do you want? " << '\n';

  //codesnippet primesequencemain
  cin >> nprimes;
  primegenerator sequence;
  while (sequence.number_of_primes_found()<nprimes) {
    int number = sequence.nextprime();
    cout << "Number " << number << " is prime" << '\n';
  }
  //codesnippet end

  return 0;
}
