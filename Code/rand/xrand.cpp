/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** the C++ random number generator
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <random>

int main() {

  //codesnippet c11rand
  // seed the generator
  std::random_device r;
  // std::seed_seq ssq{r()};
  // and then passing it to the engine does the same

  // set the default random number generator
  std::default_random_engine generator{r()};

  // distribution: real between 0 and 1
  std::uniform_real_distribution<float> distribution(0.,1.);

  cout << "first rand: " << distribution(generator) << '\n';
  //codesnippet end

  for (int i=0; i<10; i++) {
    float
      rand_right = distribution(generator);
    cout << "just a random number: rand=" << rand_right << '\n';
  }

  return 0;
}
