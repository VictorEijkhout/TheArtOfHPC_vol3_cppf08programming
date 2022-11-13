/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** refget.cxx : combining auto and references
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

class A {
private: float data;
public:
  A(float i) : data(i) {};
  auto &access() {
    return data; };
  void print() {
    cout << "data: " << data << '\n'; };
};

int main() {

  //codesnippet autoref
  A my_a(5.7);
  auto &get_data = my_a.access();
  get_data += 1;
  my_a.print();
  //codesnippet end
  
  return 0;
}
