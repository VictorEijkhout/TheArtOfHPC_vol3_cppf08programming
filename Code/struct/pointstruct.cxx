/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-8 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pointstruct.cxx : OOP stuff with a struct
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//codesnippet structobj
struct object {
  ~object() { cout << "bye bye" << '\n'; }
};
struct point : public object {
  double x; double y;
  double xpp() { x = x+1; return x; };
  point() { x = 1; };
} ;
//codesnippet end

int main() {

  {
    struct point p1;

    cout << p1.xpp() << '\n';
    cout << p1.xpp() << '\n';
    cout << p1.xpp() << '\n';
  }
  
  return 0;
}

