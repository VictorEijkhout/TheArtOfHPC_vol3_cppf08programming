/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** static.cxx : static class variables
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//codesnippet classstatic11
class myclass {
private:
  static int count;
public:
  myclass() { ++count; };
  int create_count() { return count; };
};
//codesnippet end

//codesnippet classstatic11
// in main program
int myclass::count=0;
//codesnippet end

int main() {

  myclass obj1,obj2;
  cout << "I have defined "
       << obj1.create_count()
       << " objects" << '\n';

  return 0;
}
