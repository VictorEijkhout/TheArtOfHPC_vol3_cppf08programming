/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** this.cxx : a certain idiom
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//codesnippet thisclass
class number {
private:
  float x;
public:
  number(float x) : x(x) {};
  float value() { return x; };
//codesnippet end

  number addcopy(float y) {
    x += y;
    return *this;
  };

  //codesnippet thisreference
  number& add(float y) {
    x += y;
    return *this;
  };
  number& multiply(float y) {
    x *= y;
    return *this;
  };
  //codesnippet end
};

int main() {

  {
    number mynumber(1.0);
    number more_number = mynumber.addcopy(.5);
    cout << "Original number: " << mynumber.value() << '\n';
    cout << "New number: " << more_number.value() << '\n';
  }

  cout << "This" << '\n';
  //codesnippet thisalter
  number mynumber(1.0);
  mynumber.add(.5);
  cout << mynumber.value() << '\n';

  mynumber.multiply(2.).add(1.).multiply(3.);
  cout << mynumber.value() << '\n';
  //codesnippet end
  cout << "this" << '\n';

  return 0;
}
