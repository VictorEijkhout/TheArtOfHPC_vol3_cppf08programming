/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** constcopy.cxx : demonstate yes/no copying
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

class has_int {
private:
  int mine{1};
public:
  has_int(int v) { mine = v; };
  has_int(has_int &other) { cout <<
      "(calling copy constructor)" << '\n';
    mine = other.mine;
  };
};

//codesnippet constcopy
void f_with_copy(has_int other) {
  cout << "function with copy" << '\n'; };
void f_with_ref(const has_int &other) {
  cout << "function with ref" << '\n'; };
//codesnippet end

int main() {

  has_int an_int(5);
  
//codesnippet constcopy
  cout << "Calling f with copy..." << '\n';  
  f_with_copy(an_int);

  cout << "Calling f with ref..." << '\n';  
  f_with_ref(an_int);
//codesnippet end

  cout << "... done" << '\n';
  
  return 0;
}
