/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** axpy.cxx : lazy evaluation of axpy
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <chrono>
using namespace std::chrono;

#include <cassert>

//codesnippet lazyaxpy
template< typename T >
class scaledvector {
public:
  const T& scalar;
  const vector<T>& data;
public:
  scaledvector( T x,const vector<T>& ar )
    :scalar(x),data(ar) {};
  size_t size() const { return data.size(); };
};

template< typename T >
scaledvector<T> operator*( T x,const vector<T>& ar ) {
  return scaledvector<T>(x,ar);
};

template< typename T >
vector<T>& operator+=( vector<T>& y,const scaledvector<T>& ax ) {
  assert( y.size()==ax.size() );
  for ( size_t i=0; i<y.size(); ++i )
    y[i] += ax.scalar * ax.data[i];
  return y;
};
//codesnippet end

int main() {

  const int N = 10;
  vector<float> x(N),y(N);

  y += 5.f*y;
  
  return 0;
}
