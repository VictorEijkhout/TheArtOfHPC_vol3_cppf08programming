/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** intprec.cxx : test precision of int types
 ****
 ****************************************************************/

#include <cmath>
using std::abs;

#include <iostream>
using std::cout;

template <typename T>
bool invalid_multiply(T cur,T nxt,T factor) {
  //cout << cur << " -> " << nxt << '\n';
  T progress = nxt-cur;
  float fcur = (float)cur, fnxt = (float)nxt, fgrs = (float)progress;
  float should_next = factor*fcur;
  float should_progress = should_next - fcur;
  //cout << "  s/b " << fcur << " -> " << should_next << '\n';
  return fnxt<0. || abs( (fgrs-should_progress)/should_progress )>1.e-5;
}

int main() {

  {
    short int ishort=1, factor = 10;
    for (;;) {
      short int inext = factor*ishort;
      if (invalid_multiply(ishort,inext,factor)) {
	cout << "Overflow beyond " << ishort << '\n';
	break;
      } else ishort = inext;
    }
  }
  {
    int inormal=1, factor = 10;
    for (;;) {
      int inext = factor*inormal;
      if (invalid_multiply(inormal,inext,factor)) {
	cout << "Overflow beyond " << inormal << '\n';
	break;
      } else inormal = inext;
    }
  }
  {
    long int ilong=1, factor = 10;
    for (;;) {
      long int inext = factor*ilong;
      if (invalid_multiply(ilong,inext,factor)) {
	cout << "Overflow beyond " << ilong << '\n';
	break;
      } else ilong = inext;
    }
  }
  return 0;
}

