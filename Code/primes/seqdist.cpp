/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** seqdist.cxx : test sequential distances
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <map>
using std::map;

bool isprime(int number) {
  for (int divisor=2; divisor<number; divisor++) {
    if (number%divisor==0) {
      return false;
    }
  }
  return true;
};

class primegenerator {
private:
  int numberfound{0};
  int currentnumber{2};
  int maxnumber{250000};
public:
  primegenerator() {};
  int nextprime() {
    while (!isprime(currentnumber)) {
      if (currentnumber>=maxnumber)
	throw("Can not test primes this large");
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
  int lasttest;

  primegenerator primes;
  int cur{0},prev{0},prevprev{0},maxdist{0};
  map<int,int> distance_counts;

  try {
    do {
      prevprev = prev; prev = cur;
      cur = primes.nextprime();
      int d1 = prev-prevprev,d2 = cur-prev;
      if (prevprev>=2) {
	if (d1==d2) {
	  if (d1>maxdist) {
	    maxdist = d1;
	    cout << "Found triplet "
		 << prevprev << "," << prev << "," << cur
		 << " with distances " << d1 << '\n';
	  }
	  if (distance_counts.find(d1)==distance_counts.end())
	    distance_counts[d1] = 1;
	  else
	    distance_counts[d1] += 1;
	}
      }
    } while (true);
  } catch ( ... ) { }
  for ( auto [d,c] : distance_counts )
    cout << "distance: " << d << " with count " << c << '\n';

  return 0;
}
