/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** rvaluecopy.cxx : non-working illustration of rvalue references
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

class integer {
public:
  int data{0};
public:
  integer() {};
  integer( int i ) : data(i) {
    cout << "  value!" << '\n';
  };
  integer( const integer &i ) {
    data = i.data;
    cout << "  copy!" << '\n';
  };
  integer( integer &&i ) {
    data = i.data;
    cout << "  move!" << '\n';
  };
  integer& operator=( integer &&i ) {
    cout << "  asign " << i.data << '\n';
    data = i.data;
    return *this;
  }
  integer operator+( const integer &i ) {
    int newdata = data+i.data;
    cout << "  op: " << data << "+" << i.data << "=" << newdata << '\n';
    return integer(newdata);
  };
  ~integer() {
    cout << "  destruct " << data << '\n';
  };
};

int main() {

  cout << "Init" << '\n';
  integer one(1),two(2);
  {
    cout << "Sum copy" << '\n';
    integer three( one+two );
  }
  {
    cout << "Sum assign" << '\n';
    integer four = two+two;
  }
  cout << "End" << '\n';

  return 0;
}
