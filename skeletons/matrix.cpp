/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** matrix.cxx : example of matrix class
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

class matrix {
private:
  vector<vector<double>> elements;
public:
  matrix(int m,int n)
    : elements(
               vector<vector<double>>(m,vector<double>(n))
               ) {
  }
  void set(int i,int j,double v) {
    elements.at(i).at(j) = v;
  };
  double get(int i,int j) {
    return elements.at(i).at(j);
  };
};

int main() {

  cout << "SetGet\n";
  matrix A(2,5);
  A.set(1,2,3.14);
  cout << A.get(1,2) << '\n';
  cout << "setget\n";
  
  cout << "Sum\n";
  A.set(3.);
  cout << "Sum of elements: "
       << A.totalsum() << '\n';
  cout << "sum\n";

  return 0;
}
