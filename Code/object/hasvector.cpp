/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** hasvector.cxx : member initializer on object
 ****
 ****************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class witharray {
private:
  vector<int> the_array;
public:
  witharray( int n )
    : the_array(n) {
    cout << "contains vector of size: " << the_array.size() << '\n';
  };
};

int main() {
  witharray x(5);
  return 0;
}
