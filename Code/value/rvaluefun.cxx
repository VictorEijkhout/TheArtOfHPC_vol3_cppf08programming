/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** rvalue.cxx : example
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

class Thing {
private:
  int i;
public:
  Thing( int i ) : i(i) {
    cout << "construct\n";
  };
  Thing( const Thing &t ) {
    cout << "ref copy constructor\n";
    i = t.i;
  };
  Thing( Thing &&t ) {
    cout << "rvalue copy constructor\n";
    i = t.i;
  };
  Thing inc() {
    cout << "increment\n";
    Thing t(i+1);
    return t;
  };
  Thing operator+(int i) {
    cout << "plus\n";
    Thing t(this->i+i);
    return t;
  };
};

void fun1( const Thing &t ) {
  cout << "ref thing" << '\n';
};
// void fun1( Thing t ) {
//   cout << "rvalue thing" << '\n';
// };

void fun2( const Thing &t ) {
  cout << "ref thing" << '\n';
};
void fun2( Thing &&t ) {
  cout << "rvalue thing" << '\n';
};

int main() {

  Thing five(5);

  cout << "==== without rvalue ref ====\n";
  fun1( five );
  fun1( Thing(5) );

  cout << "==== with rvalue ref ====\n";
  fun2( five );
  fun2( Thing(5) );

  return 0;
}
