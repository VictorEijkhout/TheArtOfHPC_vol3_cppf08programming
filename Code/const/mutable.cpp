/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** mutable.cxx : using the `mutable' keyword
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

//codesnippet mutenumber
class has_int {
private:
  int mine{1};
public:
  has_int(int i) { set(i); };
  // cached data!
private:
  mutable int square{-1};
public:
  void set(int i) {
    mine = i; square = -1;
  };
  int get_square() const {
    if (square<0)
      square = mine*mine;
    return square;
  };
};

int main() {

  has_int an_int(5);
  int a_square = an_int.get_square();
  cout << "square: " << a_square << '\n';

  return 0;
}
//codesnippet end
