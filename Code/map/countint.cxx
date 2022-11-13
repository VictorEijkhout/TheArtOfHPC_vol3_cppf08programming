/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** arrayprint.cxx : printable array class
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <map>
using std::map;

int main() {

  /*
   * Generate some numbers and store them in the map
   */
  map<int,int> intcount;
  for ( int i=0; i<16; i+=2) {
    int even = i%10;
    intcount[even] += 1;
  }

  /*
   * Iterate over all key/value pairs
   */
  for ( auto [num,count] : intcount ) {
    cout << "has: " << num << ", " << count << " times" << '\n';
  }

  /*
   * Test for existence of some keys
   */
  for ( auto k : {5,6} ) {
    cout << "key: " << k << " appears " << intcount.count(k) << " times" << '\n';
  }

  /*
   * Get the iterator of some keys that is present
   */
  //codesnippet intcountfind
  for ( auto k : {4,5} ) {
    auto wherek = intcount.find(k);
    if (wherek==intcount.end())
      cout << "could not find key" << k << '\n';
    else {
      auto [kk,vk] = *wherek;
      cout << "found key: " << kk << " has value " << vk << '\n';
    }
  }
  //codesnippet end

  return 0;
}
