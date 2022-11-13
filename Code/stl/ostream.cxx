/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** ostream.cxx : output a class
 ****
 ****************************************************************/


#include <iostream>
using std::cin;
using std::cout;
#include <ostream>
using std::ostream;

//codesnippet classostream
class container {
//codesnippet end
private:
  int i;
public:
  container(int i) { this->i = i; };
  //codesnippet classostream
  int value() const {
    //codesnippet end
    return i;
  //codesnippet classostream
  };
  //codesnippet end
};

//codesnippet classostream
ostream &operator<<(ostream &os,const container &i) {
  os << "Container: " << i.value();
  return os;
};
//codesnippet end

int main() {
  //codesnippet classostream
  container eye(5);
  cout << eye << '\n';
  //codesnippet end
  
  return 0;
}

