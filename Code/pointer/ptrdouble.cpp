/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-9 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** ptrdouble.cxx : shared pointers to scalar
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <memory>
using std::shared_ptr;
using std::make_shared;

int main() {

  cout << "Double" << '\n';
  {
    //codesnippet ptrdouble
    // shared pointer to allocated double
    auto array = shared_ptr<double>( new double );
    double *ptr = array.get();
    array.get()[0] = 2.;
    cout << ptr[0] << '\n';
    //codesnippet end
  }
  cout << "double" << '\n';
  cout << "Init" << '\n';
  {
    //codesnippet ptrdoubleinit
    // shared pointer to initialized double
    auto array = make_shared<double>(50);
    double *ptr = array.get();
    cout << ptr[0] << '\n';
    //codesnippet end
  }
  cout << "init" << '\n';
  

  return 0;
}
