/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** collatz.cxx : compute the Collatz sequence of an input
 ****
 **** teaches : recursion
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

class collatz {
private:
  int cur{-1};
public:
  collatz(int starting) {
    cur = starting;
  };
  int step() {
    if (cur%2==0)
      cur = cur/2;
    else
      cur = 3*cur+1;
    return cur;
  };
  int current() { return cur; };
};

int main() {
  
  for ( int starter=1; starter<1000; starter++) {
    collatz sequence(starter);
    cout << starter ;
    while (sequence.current()!=1) {
      sequence.step();
      cout << " " << sequence.current();
    } cout << '\n';
  }

  return 0;
}
