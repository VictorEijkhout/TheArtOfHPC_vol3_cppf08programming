/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** findzero.cxx : root finding
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <iomanip>
using std::setw;

#include <vector>
using std::vector;

#include <cassert>
#include <cmath>

#include "poly.h"


void find_initial_bounds( const polynomial &poly,double &left,double &right) {
  if (poly.is_odd()) {
    left = -1; right = +1;
    while ( poly.evaluate_at(left)*poly.evaluate_at(right) > 0 ) {
      left *=2; right *= 2;
    }
  } else {
    cout << "can not find outer for even" << '\n';
  }
}

void move_bounds( const polynomial &poly,
		  double& left,double& left_val,double& right, double& right_val ) {
  double mid = (left+right)/2., mid_val = poly.evaluate_at(mid);
  if ( mid_val*left_val>0 ) {
    left = mid; left_val = mid_val;
    //cout << "moving left to " ;
  } else {
    right = mid; right_val = mid_val;
    //cout << "moving right to " ;
  }
  //cout << mid << '\n';
}

double find_zero( const polynomial &poly,double left,double right) {
  double left_val = poly.evaluate_at(left),
    right_val = poly.evaluate_at(right);
  assert( left_val *right_val<=0 );
  while (abs(left_val)>1.e-8 && abs(right_val)>1.e-8) {
    move_bounds(poly,left,left_val,right,right_val);
    assert( left_val *right_val<=0 );
    cout << "values: " << left_val << " " << right_val << '\n';
  }
  return (left+right)/2;
}

int main() {

  polynomial poly;

  double left,right,zero;
  find_initial_bounds(poly,left,right);

  cout << "Finding zero between " << left << " and " << right << '\n';

  zero = find_zero(poly,left,right);

  return 0;
}

