/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** lambdafun.cxx : storing a lambda
 ****
 ****************************************************************/

//codesnippet lambdaclass
#include <functional>
using std::function;
//codesnippet end

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <string>
using std::string;
using std::to_string;

//codesnippet lambdaclass
class SelectedInts {
private:
  vector<int> bag;
  function< bool(int) > selector;
public:
  SelectedInts
      ( function< bool(int) > f ) {
    selector = f; };
  void add(int i) {
    if (selector(i))
      bag.push_back(i);
  };
  int size() {
    return bag.size(); };
  std::string string() {
    std::string s;
    for ( int i : bag )
      s += to_string(i)+" ";
    return s;
  };
};
//codesnippet end

int main() {

  SelectedInts greaterthan5
    ( [] (int i) { return i>5; } );
  int upperbound = 20;
  for (int i=0; i<upperbound; ++i)
    greaterthan5.add(i);
  // cout << "Ints under " << upperbound <<
  //   " greater than 5: " << greaterthan5.size() << '\n';
  
  int divisor;
  //codesnippet lambdaclassed
  cout << "Give a divisor: ";
  cin >> divisor; cout << '\n';
  cout << ".. using " << divisor
       << '\n';
  auto is_divisible =
    [divisor] (int i) -> bool {
      return i%divisor==0; };
  SelectedInts multiples( is_divisible );
  for (int i=1; i<50; ++i)
    multiples.add(i);
  //codesnippet end
  cout << "Multiples of " <<divisor << ": "
       << '\n'
       << multiples.string() << '\n';

  return 0;
}
