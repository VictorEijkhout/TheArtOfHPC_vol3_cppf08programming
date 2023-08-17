/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction Scientific Programming in C++/Fortran2003
 **** copyright 2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** isavector.cxx : object inheriting from vector
 ****
 ****************************************************************/

#include <iostream>
#include <vector>
using namespace std;

//codesnippet inheritfromvector
class witharray : public vector<float> {
  //codesnippet end
public:
  //codesnippet inheritfromconstructor
  witharray( float n )
    : vector<float>(n) {
  };
  //codesnippet end
};

int main() {

  //codesnippet inheritfrommain
  witharray x(5);
  x[ x.size()-1 ] = 3.14;
  cout << x.back() << '\n';
  //codesnippet end

  return 0;
}
