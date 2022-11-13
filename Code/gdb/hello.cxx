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

void say(int n) {
  cout << "hello world " << n << '\n';
}

int main() {

  for (int i=0; i<10; i++) {
    int ii;
    ii = i*i;
    ii++;
    say(ii);
  }

  return 0;
}
  
