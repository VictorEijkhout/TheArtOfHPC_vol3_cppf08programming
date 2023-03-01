/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** copyscalar.cxx : copy constructor with a simple class
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

//codesnippet classwithcopy
class has_int {
private:
  int mine{1};
public:
  has_int(int v) {
    cout << "set: " << v
         << '\n';
    mine = v; };
  has_int( has_int &h ) {
    auto v = h.mine;
    cout << "copy: " << v
         << '\n';
    mine = v; };
  void printme() {
    cout << "I have: " << mine
         << '\n'; };
};
//codesnippet end

int main() {

  //codesnippet classwithcopyuse
  has_int an_int(5);
  has_int other_int(an_int);
  an_int.printme();
  other_int.printme();
  //codesnippet end
  
  return 0;
}
