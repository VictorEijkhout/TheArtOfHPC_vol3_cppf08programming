/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017/8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** ptr2.cxx : shared pointers
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <memory>
using std::shared_ptr;
using std::make_shared;

class thing {
public:
  thing()  { cout << ".. calling constructor\n"; };
  ~thing() { cout << ".. calling destructor\n"; };
};

int main() {

  //codesnippet shareptr2
  cout << "set pointer2" << '\n';
  auto thing_ptr2 =
    make_shared<thing>();
  cout << "set pointer3 by copy"
       << '\n';
  auto thing_ptr3 = thing_ptr2;
  cout << "overwrite pointer2"
       << '\n';
  thing_ptr2 = nullptr;
  cout << "overwrite pointer3"
       << '\n';
  thing_ptr3 = nullptr;
  //codesnippet end

#if 0
  // alternatively
  auto thing_ptr2 =
    shared_ptr<thing>
      ( new thing );
#endif

  return 0;
}
