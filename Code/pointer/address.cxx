/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** address.cxx : pointer from address
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <memory>
using std::shared_ptr;

class HasY {
public:
  double y;
  HasY( double y) : y(y) {};
};

int main() {
  HasY y(5);
  //codesnippet shareaddress
  auto
    p = shared_ptr<HasY>( &y );
  p->y = 3;
  cout << "Pointer's y: "
       << p->y << '\n';
  //codesnippet end
}
