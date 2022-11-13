/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** constpoint.cxx : pointers and constness
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <memory>
using std::make_shared;
using std::shared_ptr;

//codesnippet constpoint1
class thing {
private:
  int i;
public:
  thing(int i) : i(i) {};
  void set_value(int ii) { i = ii; };
  auto value() const { return i; };
};

class has_thing {
private:
  shared_ptr<thing>
      thing_ptr{nullptr};
public:
  has_thing(int i) 
    : thing_ptr
      (make_shared<thing>(i)) {};
  void print() const {
    cout << thing_ptr->value() << '\n'; };
  //codesnippet end
  //codesnippet constpoint2
  auto get_thing_ptr() const {
    return thing_ptr; };
  //codesnippet end
  //codesnippet constpoint3
  // Error: does not compile
  // auto &get_thing_ptr() const {
  auto &access_thing_ptr() {
    return thing_ptr; };
  //codesnippet end
  //codesnippet constpoint4
private:
  shared_ptr<const thing>
      const_thing{nullptr};
public:
  has_thing(int i,int j)
    : const_thing
      (make_shared<thing>(i+j)) {};
  auto get_const_ptr() const {
    return const_thing; };
  void crint() const {
    cout << const_thing->value() << '\n'; };
  //codesnippet end
};

int main() {

  cout << "Point2" << '\n';
  {
    //codesnippet constpoint2
    has_thing container(5);
    container.print();
    container.get_thing_ptr() =
      make_shared<thing>(6);
    container.print();
    //codesnippet end
  }
  cout << "point2" << '\n';

  cout << "Point3" << '\n';
  {
    //codesnippet constpoint3
    has_thing container(5);
    container.print();
    container.access_thing_ptr() =
      make_shared<thing>(7);
    container.print();
    container.get_thing_ptr()->set_value(8);
    container.print();
    //codesnippet end
  }
  cout << "point3" << '\n';

#if 0
  {
    //codesnippet constpoint4
    has_thing constainer(1,2);
    // Error: does not compile
    constainer.get_const_ptr()->set_value(9);
    //codesnippet end
  }
#endif

  return 0;
}
