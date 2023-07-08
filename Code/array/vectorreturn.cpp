/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-9 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** vectorreturn.cxx : return vector from function
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

//codesnippet vectorreturn
vector<int> make_vector(int n) {
  vector<int> x(n);
  x.at(0) = n;
  return x;
}
//codesnippet end
  
int main() {

  //codesnippet vectorreturn
  vector<int> x1 = make_vector(10);
  // "auto" also possible!
  cout << "x1 size: " << x1.size() << '\n';
  cout << "zero element check: " << x1.at(0) << '\n';
  //codesnippet end
  
  return 0;
}
