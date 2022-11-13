/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** tuple.cxx : std::tuple
 ****
 ****************************************************************/


#include <iostream>
using std::cin;
using std::cout;

#include <cmath>

//codesnippet tuplemake
#include <tuple>
using std::make_tuple, std::tuple;
//codesnippet end

//codesnippet tuplemake
auto maybe_root1(float x) {
  if (x<0)
    return make_tuple
      <bool,float>(false,-1);
  else
    return make_tuple
      <bool,float>(true,sqrt(x));
};
//codesnippet end

//codesnippet tupledenote
tuple<bool,float>
    maybe_root2(float x) {
  if (x<0)
    return {false,-1};
  else
    return {true,sqrt(x)};
};
//codesnippet end

int main() {
  float x;
  cin >> x;
  if (false) {
    auto [succeed,y] = maybe_root1(x);
    if (succeed)
      cout << "Root of " << x
           << " is " << y << '\n';
    else
      cout << "Sorry, " << x
           << " is negative" << '\n';
  }
  
  {
    //codesnippet tupleauto
    auto [succeed,y] = maybe_root2(x);
    if (succeed)
      cout << "Root of " << x
           << " is " << y << '\n';
    else
      cout << "Sorry, " << x
           << " is negative" << '\n';
    //codesnippet end
  }
  return 0;
}

