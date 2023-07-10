/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** autoref.cxx : combining auto and references
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;

class A {
private:
  vector<int> v;
public:
  A(int n) {
    for (int i=0; i<n; ++i)
      v.push_back(i+1);
  };
  auto &access() {
    return v; };
  int size() { return v.size(); };
  auto first() { return v[0]; };
};

int main() {

  A a(5);
  cout << "a.size=" << a.size() << '\n';
  cout << " first=" << a.first() << '\n';
  {
    auto a_data = a.access();
    a_data.push_back(0);
    cout << "a.size=" << a.size() << '\n';
    for ( auto &e : a_data )
      e *= 2;
    cout << " first=" << a.first() << '\n';
  }
  {
    auto &a_data = a.access();
    a_data.push_back(0);
    cout << "a.size=" << a.size() << '\n';
    for ( auto &e : a_data )
      e *= 2;
    cout << " first=" << a.first() << '\n';
    for ( auto &e : a.access() )
      e *= 2;
    cout << " first=" << a.first() << '\n';
  }


  return 0;
}
