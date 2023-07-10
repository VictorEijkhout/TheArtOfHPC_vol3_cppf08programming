/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** virtualvec.cxx : virtual vector base
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <vector>
using std::vector;

#include "virtualvec.hpp"

class DenseVector : VirtualVector {
private:
  vector<float> values;
public:
  DenseVector( int size ) {
    values = vector<float>(size,0);
  };
  void setlinear( float v ) {
    for (int i=0; i<values.size(); ++i)
      values[i] = i*v;
  };
};

int main() {
  DenseVector v(5.1);
  v.setlinear();
  cout << v[1] << '\n';
  return 0;
}
