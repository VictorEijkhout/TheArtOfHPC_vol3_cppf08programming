/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** static.cxx : static class variables, C++17 syntax
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//codesnippet classstatic17
class myclass {
private:
  static inline int count=0;
public:
  myclass() { ++count; };
  int create_count() {
    return count; };
};
//codesnippet end

int main() {

  //codesnippet classstatic17
  myclass obj1,obj2;
  cout << "I have defined "
       << obj1.create_count()
       << " objects" << '\n';
  //codesnippet end

  return 0;
}
