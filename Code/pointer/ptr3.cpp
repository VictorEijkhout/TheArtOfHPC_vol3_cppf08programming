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

#include <vector>
using std::vector;

class thing {
public:
  thing()  { cout << ".. calling constructor\n"; };
  ~thing() { cout << ".. calling destructor\n"; };
  void f() { cout << ".. calling method\n"; };
};

int main() {

  cout << "Pointer3a" << '\n';
  //codesnippet shareptr3a
  cout << "pointer to array"
       << '\n';
  auto thing_ptr1 =
    make_shared<vector<double>>(100);
  cout << "size: "
       << thing_ptr1->size()
       << '\n';
  cout << "pointer overwrite"
       << '\n';
  thing_ptr1 = nullptr;
  //codesnippet end
  cout << "pointer3a" << '\n';

  cout << '\n';

  cout << "Pointer3b" << '\n';
  //codesnippet shareptr3b
  cout << "set pointer to array size 2"
       << '\n';
  auto thing_ptr2 =
    make_shared<vector<thing>>(2);
  thing_ptr2->at(1).f();
  cout << "alter array element"
       << '\n';
  // NOT thing_ptr2->at(0) = nullptr;
  thing_ptr2->at(0) = thing();
  cout << "overwrite pointer2"
       << '\n';
  thing_ptr2 = nullptr;
  //codesnippet end
  cout << "pointer3b" << '\n';

  cout << '\n';
  
  {
    //codesnippet shareptr3c
    cout << "set pointer to array size 2"
	 << '\n';
    auto thing_ptr3 =
      vector<thing>(2);
    thing_ptr3.at(1).f();
    cout << "alter array element"
	 << '\n';
    thing_ptr3.at(0) = thing();
    cout << "overwrite pointer2"
	 << '\n';
    //codesnippet end
  }

  return 0;
}
