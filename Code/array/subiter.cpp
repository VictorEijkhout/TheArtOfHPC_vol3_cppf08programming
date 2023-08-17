/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** subiter.cpp : sub-vector using iterators
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

#include <vector>
using std::vector;
#include <numeric>
using std::iota;

int main() {

  //codesnippet subvectorfrombeginend
  vector<int> count(5);
  iota(count.begin(),count.end(),0);
  vector<int> from1
    ( count.begin()+1,count.end()-1 );
  cout << count[1] << ","
       << from1[0] << '\n';
  from1[0] = 5;
  cout << count[1] << ","
       << from1[0] << '\n';
  //codesnippet end
  
  return 0;
}

