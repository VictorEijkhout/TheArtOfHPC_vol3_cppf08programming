/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** arraystd.cxx : use of std::vector
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

#include <vector>
using std::vector;

int main() {
  int array_length;
  cout << "How many elements? ";
  cin >> array_length;
  //examplesnippet stdvector
  vector<double> my_array(array_length);
  //examplesnippet end
  //  vector<double> my_array; my_array.reserve(array_length);
    
  for (int i=0; i<array_length; ++i) {
    double user_number;
    cout << "number " << i << "=";
    cin >> user_number;
    //examplesnippet stdvector
    my_array[i] = user_number;
    //examplesnippet end
  }
#if 0
  //examplesnippet stdvector
  my_array[array_length] = 0.123; // wrong but probably works
  my_array.at(array_length) = 0.123; // runtime error
  cout << "the array has " << my_array.size() << " elements" << '\n';
  //examplesnippet end
#endif

  return 0;
}
