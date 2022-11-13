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
#include <cmath>

float root(float n)
{
  float r;
  float n1 = n-1.1;
  r = sqrt(n1);
  return r; 
}
 
int main() {
  float x=9,y;
  for (int i=0; i<20; i++) {
    y = root(x);
    cout << "root: " << y << '\n';
    x -= 1.1;
  }

  return 0;
}

/*
  1. observe the NaN
  2. use `break' or `break if' to stop when 
     you are about to take the root of a negative number
  3. use `where' and `frame' to determine the iteration that 
     caused this.
*/
