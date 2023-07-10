/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** classvector.cxx : use of vector in class
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

#include <vector>
using std::vector;

class myvector {
private:
  vector<int> internal;
public:
  myvector(int l)
    : internal(vector<int>(l)) {};
  int size() { return internal.size(); };
  void set(int v) {
    for ( auto& e : internal )
      e = v;
  };
  myvector operator+( myvector other ) {
    int s=internal.size();
    if (s!=other.size()) throw;
    myvector result(s);
    for (int i=0; i<s; ++i)
      result.internal[i] = internal[i]+other.internal[i];
    return result;
  };
  int operator[](int i) { return internal.at(i); };
};

int main() {
  int array_length;
  cout << "How many elements? ";
  cin >> array_length;
  cout << '\n';
  
  vector<double> my_array(array_length);
  cout << "my array has length " << my_array.size() << '\n';

  vector<double> my_reserve; my_reserve.reserve(array_length);
  cout << "my reserve has length " << my_reserve.size() << '\n';
  
  myvector vc(array_length);
  cout << "my class has length " << vc.size() << '\n';

  myvector one(array_length),two(array_length);
  one.set(1); two.set(2);
  auto three = one+two;
  cout << "sum vector has value " << three[0] << '\n';

  return 0;
}
