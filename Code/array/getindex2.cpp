/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** getindex2.cxx : define indexing by ref
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

class vector10 {
private:
  int array[10];
public:
  vector10() {
    for (int i=0; i<10; ++i)
      array[i] = 7+i;
  };
  //examplesnippet refindexref
  int& operator[](int i) {
    return array[i];
  };
};
//examplesnippet end

int main() {
  vector10 v;
  //examplesnippet refindexref
  cout << v[2] << '\n';
  v[2] = -2;
  cout << v[2] << '\n';
  //examplesnippet end
  return 0;
}
