/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** constrefget.cxx : combining auto and references
 **** This Does Not Compile
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

  //codesnippet constrefget
  A my_a(5.7);
  const auto &get_data = my_a.access();
  get_data += 1; // WRONG does not compile
  my_a.print();
  //codesnippet end
  
  return 0;
}
