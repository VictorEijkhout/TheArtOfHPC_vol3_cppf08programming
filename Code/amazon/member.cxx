class B;

class A {
  friend class A;
protected:
  int i;
public:
  A(int i) : i(i) {};
  int geti() { return i; };
};

class B : public A {
public:
  B( A a ) : A(a.geti()) {};
};
