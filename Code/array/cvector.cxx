/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** cvector.cxx : vector from C array
 ****
 ****************************************************************/

#include <iostream>
using std::cerr, std::cin, std::cout;

#include <vector>
using std::vector;

int main() {

  {
    int length{53};
    //codesnippet cvector1
    float *x;
    x = (float*)malloc(length*sizeof(float));
    //codesnippet end
    if (!x) {
      cerr << "Could not allocate example 1\n";
      throw(1);
    }
    //codesnippet cvector1
    vector<float> xvector(x,x+length);
    cout << "xvector has size: " << xvector.size() << '\n';
    xvector.push_back(5);
    cout
      << "Push back was successful" << '\n';
    cout << "pushed element: "
         << xvector.at(length) << '\n';
    cout << "original array: "
	 << x[length] << '\n';
    //codesnippet end
  }

  return 0;
}
