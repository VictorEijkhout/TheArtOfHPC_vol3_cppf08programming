/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** plainget.cxx : combining auto and references
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//codesnippet autoclass
class A {
private: float data;
public:
  A(float i) : data(i) {};
  auto &access() {
    return data; };
  void print() {
    cout << "data: " << data << '\n'; };
};
//codesnippet end

int main() {

  //codesnippet autoplain
  A my_a(5.7);
  auto get_data = my_a.access();
  get_data += 1;
  my_a.print();
  //codesnippet end
  
  return 0;
}
