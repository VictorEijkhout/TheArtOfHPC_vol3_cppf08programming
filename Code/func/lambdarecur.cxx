/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** lambdarecur.cxx : lambda example
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

int main() {

  auto ipower =
    [] (int base,int power) {
      auto iipower =
	[] ( auto&& self, int base,int power ) {
	  if (power==0) return 1;
	  else return base * self(self,base,power-1);
	};
      return iipower(iipower,base,power);
    } ;
  
  cout << ipower(2,5) << '\n';
  
  return 0;
}
