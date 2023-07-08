/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** getindex1.cxx : define indexing by () and []
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

//examplesnippet refindexcopy
class vector10 {
private:
  int array[10];
public:
  //examplesnippet end
  vector10() {
    for (int i=0; i<10; i++)
      array[i] = 7+i;
  };
  //examplesnippet refindexcopy
  int operator()(int i) {
    return array[i];
  };
  int operator[](int i) {
    return array[i];
  };
};
//examplesnippet end

int main() {
  //examplesnippet refindexcopy
  vector10 v;
  cout << v(3) << '\n';
  cout << v[2] << '\n';
  /* compilation error: v(3) = -2; */
//examplesnippet end
  return 0;
}
