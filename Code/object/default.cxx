/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** default.cxx : defaulted default constructors
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//codesnippet defaultno
class IamOne {
private:
  int i=1;
public:
  void print() {
    cout << i << '\n';
  };
};
//codesnippet end


class Point {
private:
  double x,y;
public:
  //codesnippet defaulteddefault
  Point() = default;
  Point( double x,double y )
    : x(x),y(y) {};
  //codesnippet end
};

int main() {

  //codesnippet defaultno
  IamOne one;
  one.print();
  //codesnippet end

  Point x;
  Point y(1.2,3.4);
  
  return 0;
}
