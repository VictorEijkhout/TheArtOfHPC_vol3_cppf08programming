/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** lambdaex.cxx : lambda example
 ****
 ****************************************************************/

#include <functional>
using std::function;

#include <iostream>
using std::cin;
using std::cout;

//codesnippet lambdapass
void apply_to_5
    ( function< void(int) > f ) {
  f(5);
}
//codesnippet end

int main() {

  cout << "Direct\n";
  cout <<
    //codesnippet lambdaexp
  [] (float x,float y) -> float {
    return x+y; } ( 1.5, 2.3 )
    //codesnippet end
  << '\n';
  cout << "direct\n";

  cout << "Var\n";
  //codesnippet lambdavar
  auto summing = 
    [] (float x,float y) -> float {
    return x+y; };
  cout << summing ( 1.5, 2.3 ) << '\n';
  cout << summing ( 3.7, 5.2 ) << '\n';
  //codesnippet end
  cout << "var\n";
  
  cout << "Pass\n";
  //codesnippet lambdapass
  apply_to_5
    ( [] (int i) {
      cout << "Int: " << i << '\n'; } );
  //codesnippet end
  cout << "pass\n";
  
  return 0;
}
