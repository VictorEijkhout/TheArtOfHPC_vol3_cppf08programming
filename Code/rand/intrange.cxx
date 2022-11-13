/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** intrange: problems with the C random number generator
 ****
 **** THIS DOES NOT DEMONSTRATE ANYTHING
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;

int main() {

  int period{0};
  int init = rand();
  for (;;) {
    int other = rand();
    period++;
    if (other==init) break;
  }
  cout << "Period: " << period << '\n';

  vector<int> count(6);
  for (int i=0; i<period ; i++) {
    int dice = rand() % 6;
    count.at(dice)++;
  }
  cout << "Counts:" ;
  for ( auto c : count )
    cout << " " << c;
  cout << '\n';

  for (int i=0; i<period ; i++) {
    int ifraction = rand()/RAND_MAX;
    if (ifraction==1.)
      cout << "at iteration: " << i << '\n';
  }

  return 0;
}
