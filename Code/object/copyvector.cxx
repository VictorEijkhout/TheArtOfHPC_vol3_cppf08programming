/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** copyvector.cxx : copy constructor with a class containing vector
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <vector>
using std::vector;

//codesnippet classwithcopyvector
class has_vector {
private:
  vector<int> myvector;
public:
  has_vector(int v) { myvector.push_back(v); };
  void set(int v) { myvector.at(0) = v; };
  void printme() { cout
      << "I have: " << myvector.at(0) << '\n'; };
};
//codesnippet end

int main() {

  //codesnippet classwithcopyvectoruse
  has_vector a_vector(5);
  has_vector other_vector(a_vector);
  a_vector.set(3);
  a_vector.printme();
  other_vector.printme();
  //codesnippet end
  
  return 0;
}
