/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** equals.cxx : equality in floating point is tricky
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;
#include <iomanip>
using std::setw;
using std::scientific;
using std::setprecision;

#include <vector>
using std::vector;

template < typename floattype,char ft >
void testfloat( int div ) {
  floattype one = static_cast<float>(1);
  floattype reciprocal = one/static_cast<floattype>(div);
  cout << ft << ": ";
  if (ft=='s')
    cout << setw(2) << div << " * 1/"
	 << setw(2) << div << " - 1 = ";
  else
    cout << "                ";
  cout << scientific << setprecision(3) << div*reciprocal-one << "; ";
  if (ft=='s')
    cout << setw(2) << div << "^2 * 1/"
	 << setw(2) << div << "^2 -1 = ";
  else
    cout << "                   ";
  cout << scientific << setprecision(3)  << div*div*(reciprocal*reciprocal)-one << '\n';
}

int main() {

  int div; cin >> div;
  testfloat<float, 's'>(div);
  testfloat<double,'d'>(div);

  return 0;

}
