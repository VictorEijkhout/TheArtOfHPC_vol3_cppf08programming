/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** idxmax.cxx : static array length examples
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int main() {

  int numbers[] = {1,4,2,6,5};
  //examplesnippet idxmax
  int tmp_idx = 0;
  int tmp_max = numbers[tmp_idx];
  for (int i=0; i<5; i++) {
    int v = numbers[i];
    if (v>tmp_max) {
      tmp_max = v; tmp_idx = i;
    }
  }
  cout << "Max: " << tmp_max
       << " at index: " << tmp_idx << '\n';
  //examplesnippet end
    
  return 0;
}
