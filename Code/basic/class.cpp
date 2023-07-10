/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** class.cxx : illustration of classes and objects
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

//codesnippet intclass
class object_with_an_int {
private:
  int stored_integer;
public:
  // constructor: code that makes the object
  object_with_an_int( int the_int ) {
    stored_integer = the_int;
  };
  void increase() {
    ++stored_integer;
  };
  //codesnippet end
  //codesnippet intclassby
  void increase(int);
  //codesnippet end
  void print() {
    cout << "We are storing: " << stored_integer << '\n';
  };
};
//codesnippet end

//codesnippet intclassby
void object_with_an_int::increase(int by) {
  stored_integer += by;
};
//codesnippet end

int main() {
//codesnippet intclass
  object_with_an_int has_an_int(5);
  has_an_int.increase();
  has_an_int.print();
//codesnippet end
  return 0;
}
