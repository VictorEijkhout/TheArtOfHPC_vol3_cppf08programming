// -*- c++ -*-
/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** poly.h : polynomial class proto
 ****
 ****************************************************************/

#include <vector>

class polynomial {
private:
  std::vector<double> coefficients;
public:
  polynomial();
  // creation related
  void read();
  void print();
  void set_positive();
  // stats
  int degree();
  bool is_even() const; bool is_odd() const;
  // numeric
  double evaluate_at(double x) const;
};

