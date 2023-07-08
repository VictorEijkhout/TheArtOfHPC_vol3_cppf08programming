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

int main() {

  cout << "==== ordinary copy ====\n";
  Thing five(5);
  Thing also_five(five);

  cout << "==== copy ====\n";
  //  Thing six = five.inc();
  Thing also_six( five.inc() );

  cout << "==== copy from rvalue ====\n";
  //  Thing seven = five+2;
  Thing also_seven( five+2 );

  return 0;
}
