/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** the C random number generator
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

int main() {

  // this test is meaningless.
  // I thought operator precedence was funky but it's not.
  for (int i=0; i<10; i++) {
    float rand_wrong = (float) rand()/(RAND_MAX);
    cout << "parentheses wrong: rand=" << rand_wrong << '\n';
  }
  
  for (int i=0; i<10; i++) {
    float rand_right = (float) rand()/(float)RAND_MAX;
    cout << "just a random number: rand=" << rand_right << '\n';
  }

  return 0;
}
