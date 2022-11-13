/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** arraynew.cxx : allocation of arrays through new
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//examplesnippet arrayfromfunc
void make_array( int **new_array, int length ) {
  *new_array = new int[length];
}
//examplesnippet end

//examplesnippet arrayinclass
class with_array{
private:
  int *array;
  int array_length;
public:
  with_array(int size) {
    array_length = size;
    array = new int[size];
  };
  ~with_array() {
    delete array;
  };
};
//examplesnippet end
  
int main() {

//examplesnippet arrayfromfunc
  int *the_array;
  make_array(&the_array,10000);
//examplesnippet end
  for (int i=0; i<10000; i++)
    the_array[i] = i+5;

//examplesnippet arrayinclass
  with_array thing_with_array(12000);
//examplesnippet end

  return 0;
}
