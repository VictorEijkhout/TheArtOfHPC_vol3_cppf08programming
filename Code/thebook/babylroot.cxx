/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** babylroot.cxx : babylonian root finding
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <iomanip>
using std::scientific;

#include <cmath>

int main() {

  float number,tolerance;
  cout << "Enter number and tolerance: ";
  cin >> number;
  cin >> tolerance;
  cout << '\n';

  float root = number;
  while ( abs(root*root - number) > tolerance ) {
    float prev = root;
    root = .5 * ( root + number/root );
    if (prev==root) {
      cout << "bailing out with no improvement" << '\n';
      break;
    }
  }
  cout << "Found sqrt( " << number << " ) = " << scientific << root;
  if (root*root==number)
    cout << " which is exact!";
  else
    cout << " which has an error of " << abs(root*root-number);
  cout << '\n';

  return 0;
}
