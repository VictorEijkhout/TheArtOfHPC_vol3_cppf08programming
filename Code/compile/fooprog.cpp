/****************************************************************
 ****
 **** This program source is part of
 **** Introduction to High-performance Scientific Computing
 **** by Victor Eijkhout
 **** copyright Victor Eijkhout 2011-2021
 ****
 **** fooprog.c : simple main program using external function
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <string>
using std::string;

extern void bar(string);

int main() {
  bar("hello world\n");
  return 0;
}
