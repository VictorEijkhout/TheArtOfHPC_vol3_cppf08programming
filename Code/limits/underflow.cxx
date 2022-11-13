/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016=2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** underflow.cxx : illustration of underflow
 **** this example is no-op on most architectures. Try IBM Power?
 ****
 ****************************************************************/

#include <iostream>
#include <limits>
#include <cmath>
#include <cfenv>

int main() {

  auto tb = std::numeric_limits<double>::tinyness_before;
  std::cout << "Tinyness before: " << std::boolalpha
	    << tb << '\n';
 
  double min_float = std::numeric_limits<double>::min();
  double denorm_max = std::nextafter(min_float, 0);
  std::cout << "min float:  " << std::hexfloat << min_float << '\n';
  std::cout << "max denorm: " << denorm_max << '\n';

  double multiplier = 1 + std::numeric_limits<double>::epsilon();
 
  std::feclearexcept(FE_ALL_EXCEPT);
 
  double result = denorm_max*multiplier; // Underflow only if tinyness_before
 
  if(std::fetestexcept(FE_UNDERFLOW))
    std::cout << "Underflow detected\n";
  else
    std::cout << "No underflow detected\n";
 
  std::cout << std::scientific << denorm_max << " x " << multiplier  <<  " = "
	    << result << '\n';
  std::cout << std::hexfloat   << denorm_max << " x " << multiplier  <<  " = "
	    << result << '\n';
}
