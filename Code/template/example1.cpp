/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2021-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** example.cxx : nonsense example to see things in action
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

//codesnippet store1class
template< typename T >
class Store {
private:
  T stored;
public:
  Store(T v) : stored(v) {};
  T value() { return stored;};
//codesnippet end
//codesnippet store1method
  Store copy() { return Store(stored); };
  Store<T> negative() { return Store<T>(-stored); };
//codesnippet end
};

int main() {

  cout << "StoreI5\n";
  //codesnippet storei5
  Store<int> i5(5);
  cout << i5.value() << '\n';
  //codesnippet end
  cout << "storei5\n";

  Store<float> f314(3.14);
  cout << f314.value() << '\n';

  cout << "StoreF314\n";
  //codesnippet store1copy
  Store<float> also314 = f314.copy();
  cout << also314.value() << '\n';
  Store<float> min314 = f314.negative();
  cout << min314.value() << '\n';
  //codesnippet end
  cout << "storef314\n";

  return 0;
}

