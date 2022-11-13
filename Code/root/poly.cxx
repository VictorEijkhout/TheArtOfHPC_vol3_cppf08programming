// -*- c++ -*-
/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** poly.cxx : polynomial class implementation
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include "poly.h"

polynomial::polynomial() {
  read(); set_positive(); print();
};

void polynomial::read() {
  int degree;
  std::cout << "Degree?";
  std::cin >> degree ;
  std::cout << '\n';

  coefficients = std::vector<double>(degree+1);
  for (int c=0; c<=degree; c++) {
    std::cout << "coeff" << c << ":";
    std::cin >> coefficients.at(c);
  }
  std::cout << '\n';
};

void polynomial::set_positive() {
  if (coefficients[0]<0) {
    std::cout << "Flipping to get positive leading coefficient" << '\n';
    for (int ic=0; ic<coefficients.size(); ic++)
      coefficients[ic] = -coefficients[ic];
  }
};

void polynomial::print() {
  std::cout << "Polynomial: ";
  int d = coefficients.size()-1;
  for (int c=0; c<coefficients.size(); c++) {
    std::cout << coefficients[c] << " x^" << d-c;
    if (c<coefficients.size()-1) std::cout << " + ";
  }
  std::cout << '\n';
};

bool polynomial::is_even() const { return coefficients.size()%2==1; };
bool polynomial::is_odd() const  { return coefficients.size()%2==0; };

double polynomial::evaluate_at(double x) const {
  double r=coefficients[0];
  for (int c=1; c<coefficients.size(); c++)
    r = x*r + coefficients[c];
  return r;
};


