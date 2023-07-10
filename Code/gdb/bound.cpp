/****************************************************************
 ****
 **** This program source is part of
 **** Introduction to High-performance Scientific Computing
 **** by Victor Eijkhout
 **** copyright Victor Eijkhout 2011-2020
 ****
 **** gdb example program
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <vector>
using std::vector;

int main() {

  vector<float> data(20);
  for ( int i=0; ; ++i )
    data.at(i) = i;

  return 0;
}
  
