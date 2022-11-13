/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** optional.cxx : optional results
 ****
 ****************************************************************/


#include <iostream>
using std::cin;
using std::cout;

#include <cmath>

//codesnippet rootandvalid
#include <tuple>
using std::tuple, std::pair;
//codesnippet end

//codesnippet rootvariantdef
#include <variant>
using std::variant, std::get_if;
//codesnippet end

#include <optional>
using std::optional;

//codesnippet rootorerror
bool RootOrError(float &x) {
  if (x<0)
    return false;
  else
    x = sqrt(x);
  return true;
};
//codesnippet end

//codesnippet rootandvalid
pair<bool,float> RootAndValid(float x) {
  if (x<0)
    return {false,x};
  else
    return {true,sqrt(x)};
};
//codesnippet end

//codesnippet rootvariantdef
variant<bool,float> RootVariant(float x) {
  if (x<0)
    return false;
  else
    return sqrt(x);
};
//codesnippet end

//codesnippet mayberootptr
optional<float> MaybeRoot(float x) {
  if (x<0)
    return {};
  else
    return sqrt(x);
};
//codesnippet end

int main() {

  float x;
  x = 2;
  //codesnippet rootorerror
  for ( auto x : {2.f,-2.f} ) 
    if (RootOrError(x))
      cout << "Root is " << x << '\n';
    else
      cout << "could not take root of " << x << '\n';
  //codesnippet end

  //codesnippet rootandvalid
  for ( auto x : {2.f,-2.f} ) 
    if ( auto [ok,root] = RootAndValid(x) ; ok )
      cout << "Root is " << root << '\n';
    else
      cout << "could not take root of " << x << '\n';
  //codesnippet end
  
  //codesnippet rootvariantuse
  for ( auto x : {2.f,-2.f} ) {
    auto okroot = RootVariant(x);
    auto root = get_if<float>(&okroot); 
    if ( root )
      cout << "Root is " << *root << '\n';
    auto nope = get_if<bool>(&okroot);
    if (nope)
      cout << "could not take root of " << x << '\n';
  }
  //codesnippet end
  
  //codesnippet mayberootptr
  for ( auto x : {2.f,-2.f} ) 
    if ( auto root = MaybeRoot(x) ; root.has_value() )
      cout << "Root is " << root.value() << '\n';
    else
      cout << "could not take root of " << x << '\n';
  //codesnippet end

  return 0;
}

