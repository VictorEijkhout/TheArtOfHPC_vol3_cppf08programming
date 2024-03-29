/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** constat.cxx : explore const overloading
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

//codesnippet constatclass
class has_array {
private:
  vector<float> values;;
public:
  has_array(int l,float v)
    : values(vector<float>(l,v)) {};
  auto& at(int i) {
    cout << "var at" << '\n';
    return values.at(i); };
  const auto& at (int i) const {
    cout << "const at" << '\n';
    return values.at(i); };
  auto sum() const {
    float p;
    for ( int i=0; i<values.size(); ++i)
      p += at(i);
    return p;
  };
};

int main() {

  int l; float v;
  cin >> l; cin >> v;
  has_array fives(l,v);
  cout << fives.sum() << '\n';
  fives.at(0) = 2;
  cout << fives.sum() << '\n';
  //codesnippet end
  
  return 0;
}
