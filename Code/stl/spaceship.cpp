/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** spaceship.cxx : example
 ****
 ****************************************************************/

#include <iostream>
#include <iomanip>
using std::cin, std::cout, std::endl, std::boolalpha;

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <array>
using std::array,std::to_array;

//codesnippet spaceshipclass1
class Record {
private:
  static inline int nrecords{0};
  int myrecord{-1};
  string name;
public:
  Record( string name )
    : name(name) { myrecord = nrecords++; };
  //codesnippet end
  //codesnippet spaceshipclass1order
  std::strong_ordering operator<=>( const Record& other ) {
    return myrecord<=>other.myrecord;
  };
  bool operator==( const Record& other) {
    return myrecord==other.myrecord;
  };
  //codesnippet end
};

#include <compare>
//codesnippet spaceshipclass2
template<typename T>
class Coordinate {
private:
  array<T,2> the_array;
public:
  Coordinate( T x,T y )
    : the_array( to_array({x,y} ) ) {};
  //codesnippet end
  //codesnippet spaceshipclass2order
  std::partial_ordering operator<=>( const Coordinate& other ) const {
    std::strong_ordering c = the_array[0] <=> other.the_array[0];
    for (int i = 1; i <the_array.size(); ++i) {
      if ((the_array[i] <=> other.the_array[i]) != c)
        return std::partial_ordering::unordered;
    }
    return c;
  };
  bool operator==( const Coordinate& other ) const {
    for ( int ic=0; ic<the_array.size(); ic++ ) 
      if (the_array[ic]!=other.the_array[ic])
	return false;
    return true;
  };
  //codesnippet end
};

int main() {

  cout << "Record\n";
  //codesnippet spaceshipclass1test
  Record alice("alice"), bob("bob");
  cout << "expect  t f  t t  f f\n";
  cout << boolalpha << (alice==alice) << '\n';
  cout << boolalpha << (alice==bob) << '\n';
  cout << boolalpha << (alice<=bob) << '\n';
  cout << boolalpha << (alice<bob) << '\n';
  cout << boolalpha << (alice>=bob) << '\n';
  cout << boolalpha << (alice>bob) << '\n';
  //codesnippet end
  cout << " .. record\n";
  
  cout << "Partial\n";
  //codesnippet spaceshipclass2test
  Coordinate<int> p12(1,2),p24(2,4),p31(3,1);
  cout << "expect t t f\n";
  cout << boolalpha << (p12==p12) << '\n';
  cout << boolalpha << (p12<p24) << '\n';
  cout << boolalpha << (p12<p31 or p12>p31 or p12==p31) << '\n';
  //codesnippet end
  cout << " .. partial\n";

  return 0;
}
