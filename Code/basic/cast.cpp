/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** cast.cxx : effects of type conversion
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

int main() {

  int i = 5;
  float ix,i5 = 5.e0;
  ix = i;
  if (ix==i5)
    cout << "int to float worked" << '\n';
  else
    cout << "int to float introduced junk: " << ix-i5 << '\n';

  double ex,e5;

  ix = (float)5;
  e5 = (double)5;
  ex = ix;
  if (ex==e5)
    cout << "float to double worked for int" << '\n';
  else
    cout << "float to double for int introduced junk: " << ex-e5 << '\n';

  ix = (float)5.1;
  e5 = (double)5.1;
  ex = ix;
  if (ex==e5)
    cout << "float to double worked" << '\n';
  else
    cout << "float to double introduced junk: " << ex-e5 << '\n';

  ex = (double)ix;
  if (ex==e5)
    cout << "float to double with cast worked" << '\n';
  else
    cout << "float to double with cast introduced junk: " << ex-e5 << '\n';

  return 0;
}

