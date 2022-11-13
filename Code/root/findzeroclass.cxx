/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** findzeroclass.cxx : root finding library based on OOP
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

#include "findzeroclass.h"

bool polynomial::is_proper() {
  return coefficients.size()>0 and coefficients.front()!=0.;
};

bool polynomial::is_odd() {
  return coefficients.size()%2==0;
}

double polynomial::evaluate_at( double x ) {
  double r=coefficients[0];
  for (int c=1; c<coefficients.size(); c++)
    r = x*r + coefficients[c];
  return r;
};

void polynomial::find_initial_bounds( double &left,double &right ) {
  if (is_odd()) {
    left = -1; right = +1;
    while ( evaluate_at(left)*evaluate_at(right) > 0 ) {
      left *=2; right *= 2;
    }
  } else {
    throw("can not find outer for even");
  }
}

void polynomial::move_bounds_closer( double& left_x,double& right_x ) {
    if (left_x>=right_x)
	throw("bounds in reverse order");
    double
	left_val = evaluate_at(left_x),
	right_val = evaluate_at(right_x);
    if (left_val*right_val>0)
	throw("values in bounds have same sign");
    double
	mid_x = (left_x+right_x)/2.,
	mid_val = evaluate_at(mid_x);
    if ( mid_val*left_val>0 ) {
	left_x = mid_x; 
    } else {
	right_x = mid_x;
  }
}

double polynomial::find_zero( double prec,bool trace ) {
  double left=-1., right=+1.;
  find_initial_bounds(left,right);
  double
    left_val = evaluate_at(left),
    right_val = evaluate_at(right);
  //assert( left_val *right_val<=0 );
  while (abs(left_val)>prec && abs(right_val)>prec) {
    move_bounds_closer(left,right);
    if (trace)
      cout << "move bounds to " << left << "," << right << '\n';
    left_val = evaluate_at(left);
    right_val = evaluate_at(right);
    //assert( left_val *right_val<=0 );
  }
  return (left+right)/2;
}
