/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** findzerolib.cxx : root finding library
 ****
 ****************************************************************/

#include <vector>

//codesnippet usingpolyabbrev
using polynomial = vector<double>;
//codesnippet end

std::vector<double> set_coefficients();

bool is_proper_polynomial( const std::vector<double>& coefficients );

bool is_odd( const std::vector<double>& coefficients );

//codesnippet evaluateatproto
double evaluate_at( const std::vector<double>& coefficients,double x);
//codesnippet end

void find_initial_bounds( const std::vector<double>& coefficients,double &left,double &right);

void move_bounds_closer( const std::vector<double>& coefficients,
		  double& left,double& right );

double find_zero( const std::vector<double>& coefficients,double,bool=false );
