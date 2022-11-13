/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** segmentation.cxx : generate segmentation fault
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int main() {

  //codesnippet vectoroutofbound
  vector<float> v(10,2);
  for (int i=5; i<6; i--)
    cout << "element " << i
	 << " is " << v[i] << '\n';
  //codesnippet end

  return 0;
}
