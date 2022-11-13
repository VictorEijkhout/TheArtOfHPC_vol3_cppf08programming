#include <iostream>
using std::cin;
using std::cout;

#include "rvaluecopyhead.h"

integer::integer( int i ) : data(i) {
  std::cout << "construct " << i << '\n';
};

integer::integer( const integer &i ) {
  data = i.data;
  std::cout << "copy!" << '\n';
};

integer::integer( const integer &&i ) {
  data = i.data;
  std::cout << "ccopy!" << '\n';
};

integer integer::operator+( const integer &i ) {
  return integer(data+i.data);
};

