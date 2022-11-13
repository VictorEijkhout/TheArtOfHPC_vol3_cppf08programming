/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** bubble.cxx : an bubble sort program
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <iomanip>
using std::setw;

#include <vector>
using std::vector;

//codesnippet swaplocs
void swapij( vector<int> &array,int i ) {
  int t = array[i];
  array[i] = array[i+1];
  array[i+1] = t;
}
//codesnippet end

int main() {
  vector<int> a1(2);
  a1[0] = 5; a1[1] = 3;
  swapij(a1,0);
  cout << "Location 0: " << a1[0] << " is now less then location 1: " << a1[1] << '\n';
  
  return 0;
}
