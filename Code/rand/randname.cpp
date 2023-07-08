/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2020-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** randname.cxx : random with namespaces
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <random>

//codesnippet randomspace
class generate {
private:
  static inline std::default_random_engine engine;
public:
  static int random_int(int max) {
    std::uniform_int_distribution<> ints(1,max);
    return ints(generate::engine);
  };
};
//codesnippet end

int main() {

  cout << "Three ints: "
       << generate::random_int(100) << ", "
       << generate::random_int(100) << ", "
       << generate::random_int(100) << ".\n";

  return 0;
}
