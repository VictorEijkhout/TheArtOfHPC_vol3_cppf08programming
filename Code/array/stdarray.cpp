/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** stdarray.cxx : standard array class
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;

//codesnippet incstdarray
#include <array>
using std::array;
//codesnippet end

template<int d>
class arrayclass {
private:
  array<int,d> data;
public:
  arrayclass( array<int,d> data )
    : data(data) {};
  int volume() {
    int v{1};
    for ( auto dd : data )
      v *= dd;
    return v;
  };
};

int main() {

  //codesnippet usestdarray
  {
    array<float,5> v5;
    cout << "size: " << v5.size() << '\n';
    // WRONG: such function
    // v5.push_back(2);
  }
  //codesnippet end

  {
    array<int,3> i3{17,19,23};
    arrayclass<2> coord2( {3,5} );
    cout << "volume s/b 15: " << coord2.volume() << '\n';

    array i4{1,2,3,4};
    // DOES NOT COMPILE: array not4{1.5,2,3,4};
  }
  
  {
    array<int,3> i3 = {5};
    cout << i3[2] << " s/b 5\n";
    auto i4 = array<int,4>();
    cout << i4[2] << '\n';
  }

  return 0;
}
