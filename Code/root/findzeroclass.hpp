/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** findzeroclass.cxx : root finding library based on OOP
 ****
 ****************************************************************/

#include <vector>

class polynomial {
private:
  std::vector<double> coefficients;
public:
  polynomial( std::vector<double> c )
    : coefficients(c) {};
  bool is_proper();
  bool is_odd();
  double evaluate_at(double x);
  void find_initial_bounds( double &left,double &right);
  void move_bounds_closer( double& left,double& right );
  double find_zero( double,bool=false );
};
