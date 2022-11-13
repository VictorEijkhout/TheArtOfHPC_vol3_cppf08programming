#include <iostream>
using std::cout;

class Inner {
private:
  int i;
public:
  Inner() {
    cout << "default constructor for Inner" << '\n';
  };
  Inner( const Inner &in ) {
    cout << "copy constructor for Inner" << '\n';
  };
  Inner(int i) : i(i) {
    cout << "regular constructor for Inner" << '\n';
  };
};

class Outer {
  Inner one;
public:
  Outer(Inner i)
    : one(i) {};
  Outer(int i)
    : one(Inner(i)) {};
  Outer(int i,int j) {
    one = Inner(i); };
};

int main() {
  cout << "Set from Inner" << '\n';
  Outer out1(Inner(1));
  cout  << '\n';

  cout << "Set by member initialization" << '\n';
  Outer out2(1);
  cout  << '\n';

  cout << "Set by explicit creation" << '\n';
  Outer out3(3,4);
  cout  << '\n';

  return 0;
}
