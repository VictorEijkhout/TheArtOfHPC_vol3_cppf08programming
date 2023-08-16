/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** toarray.cxx : more standard array class
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

#include <array>
using std::array, std::to_array;

//codesnippet passarray1
float first_of_three( array<float,3> fff ) {
  return fff[0];
};
//codesnippet end

//codesnippet passarray2
template<unsigned long int d>
float first_of_bunch( array<float,d> fff ) {
  return fff[0];
};
//codesnippet end

int main() {

  //codesnippet passarray1
  cout << first_of_three( { 1.5 , 2.5 , 3.5 } ) << '\n';
  //codesnippet end

  //codesnippet passarray2
  // DOES NOT COMPILE:
  //   cout << first_of_bunch( { 1.5f , 2.5f , 3.5f } ) << '\n';
  // couldn't deduce template parameter 'd'
  //codesnippet end

  //codesnippet passarray3
  // template parameter `d' can be deduced from `to_array':
  cout << first_of_bunch( to_array( { 1.5f , 2.5f , 3.5f } ) ) << '\n';
  //codesnippet end

  // This is asking too much:
  // cout << first_of_bunch( { 1.5f , 2.5f , 3.5f } ) << '\n';
  // Also doesn't work:
  // cout << first_of_bunch( to_array<float,3>( { 1.5f , 2.5f , 3.5f } ) ) << '\n';

  return 0;
}
