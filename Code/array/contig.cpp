/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** contig.cxx : handling of 2D arrays
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

//examplesnippet arraypass2d
void print12( int ar[][6] ) {
  cout << "Array[1][2]: " << ar[1][2] << '\n';
  return;
}
//examplesnippet end

//examplesnippet arraywrap
void print06( int ar[][6] ) {
  cout << "Array[0][6]: " << ar[0][6] << '\n';
  return;
}
//examplesnippet end

int main() {

  {
    //examplesnippet arraypass2d
    int array[5][6];
    array[1][2] = 3;
    print12(array);
    //examplesnippet end
  }

  {
    //examplesnippet arraywrap
    int array[5][6];
    array[1][0] = 35;
    print06(array);
    //examplesnippet end
  }

  return 0;
}
