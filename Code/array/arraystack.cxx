/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** arraystack.cxx : from stackoverflow, a vector class that can not be resized
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

template <class T, class A = std::allocator<T>>
struct FixedVector : private std::vector<T, A>
{
  using FixedVector::vector::vector;
  using FixedVector::vector::operator=;
  using FixedVector::vector::get_allocator;
  using FixedVector::vector::at;
  using FixedVector::vector::front;
  using FixedVector::vector::back;
  using FixedVector::vector::data;
  using FixedVector::vector::begin;
  using FixedVector::vector::cbegin;
  using FixedVector::vector::end;
  using FixedVector::vector::cend;
  using FixedVector::vector::empty;
  using FixedVector::vector::size;
};

int main() {
  FixedVector<double> x;
  x[2] = 3;
  cout << x.size() << '\n';

  return 0;
}
