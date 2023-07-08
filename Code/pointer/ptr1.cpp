/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** ptr1.cxx : shared pointers
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <memory>
using std::shared_ptr;
using std::make_shared;

//codesnippet thingcall
class thing {
public:
  thing()  { cout << ".. calling constructor\n"; };
  ~thing() { cout << ".. calling destructor\n"; };
};
//codesnippet end

int main() {

  //codesnippet shareptr1
  cout << "set pointer1"
       << '\n';
  auto thing_ptr1 =
    make_shared<thing>();
  cout << "overwrite pointer"
       << '\n';
  thing_ptr1 = nullptr;
  //codesnippet end

#if 0
  // alternatively
  auto thing_ptr1 = shared_ptr<thing>( new thing );
#endif

  return 0;
}
