#include <iostream>

using namespace std;

class A {
public:
  virtual void f() = 0;
};

class B1 : public A {
public:
  virtual void f() { cout << "1\n"; };
};

class B2 : public A {
public:
  virtual void f() { cout << "2\n"; };
};

class B3 : public A {
public:
  virtual void f() { cout << "3\n"; };
};

int main() {
  A a1 = B1(); a1.f();
  A a2 = B2(); a2.f();
  A a3 = B3(); a3.f();
  return 0;
}
