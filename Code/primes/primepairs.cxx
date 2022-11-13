/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** primepairs.cxx : pairs of prime numbers
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

class primes {
public:
  int numberfound{0};
  int currentnumber{2};
  primes() {};
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
};

int main() {

  primes sequence1,sequence2;
  for (;;) {
    int 
      p = sequence1.numberfound,
      q = sequence2.numberfound;
    while (q<p)
      q = sequence2.nextprime();
    cout << "Product: " << p*q << '\n';
    if (p>100 && q>100)
      break;
    sequence1.nextprime();
  }

  return 0;
}
