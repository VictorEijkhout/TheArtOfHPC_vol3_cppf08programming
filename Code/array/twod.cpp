/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** arraytime.cxx : time the overhead for flexible vectors
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int main() {

  vector<float> array(50);
  cout << "Array length: " << array.size() << '\n';
  
  vector< vector<float> > matrix(100,array);
  cout << "Matrix length: " << matrix.size() << '\n';
  cout << ".. first row length: " << matrix.at(0).size() << '\n';

  matrix[0][1] = 3.14;
  cout << ".. this had better not be 3.14: " << matrix[1][0] << '\n';

  return 0;
}
