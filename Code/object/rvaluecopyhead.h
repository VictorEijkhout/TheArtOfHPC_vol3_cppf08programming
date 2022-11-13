#include <iostream>

class integer {
public:
  int data{0};
public:
  integer() {};
  integer( int i );
  integer( const integer &i );
  integer( const integer &&i );
  integer operator+( const integer &i );
};
