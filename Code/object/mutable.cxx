/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** mutable.cxx : mutable const members
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <optional>
using std::optional;

class complicated {
public:
  complicated(int n) {
    cout << "making complicated thing\n";
  };
};

//codesnippet withmutable
class has_stuff {
private:
  mutable optional<complicated> thing = {};
public:
  const complicated& get_thing() const {
    if ( not thing.has_value() )
      thing = complicated(5);
    else cout << "thing already there\n";
    return thing.value();
  };
};
//codesnippet end

int main() {

  has_stuff mystuff;
  auto mything = mystuff.get_thing();
  mything = mystuff.get_thing();
  mything = mystuff.get_thing();

  return 0;
}
