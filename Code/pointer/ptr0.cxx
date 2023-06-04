/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** ptr1.cxx : shared pointers
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

  //codesnippet shareptr0
  cout << "Outside\n";
  {
    thing x;
    cout << "create done\n";
  }
  cout << "back outside\n";
  //codesnippet end

#if 0
  // alternatively
  auto thing_ptr1 = shared_ptr<thing>( new thing );
#endif

  return 0;
}
