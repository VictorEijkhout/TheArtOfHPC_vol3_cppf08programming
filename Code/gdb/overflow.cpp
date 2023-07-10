/****************************************************************
 ****
 **** This program source is part of
 **** Introduction to High-performance Scientific Computing
 **** by Victor Eijkhout
 **** copyright Victor Eijkhout 2011-2023
 ****
 **** hello.cxx : gdb example program for int overflow
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

//codesnippet gdbshort
void say(short n) {
  cout << "hello world " << n << '\n';
}

int main() {

  for (short i=0; ; i+=20) {
    short ii;
    ii = i*i;
    ++i;
    say(ii);
  }

  return 0;
}
//codesnippet end
