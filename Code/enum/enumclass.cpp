/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** enum.cxx : examples of enums
 ****
 ****************************************************************/

#include <iostream>
using namespace std;

int main() {
  
  //codesnippet enumclass
  enum class colors { red,yellow,green };
  cout << static_cast<int>( colors::red ) << ","
       << static_cast<int>( colors::yellow ) << ","
       << static_cast<int>( colors::green ) << '\n';
  //codesnippet end

  //codesnippet enumclassint
  enum class flag : unsigned int { red,white,blue };
  // but we still need to cast them
  cout << static_cast<int>( flag::red ) << ","
       << static_cast<int>( flag::white ) << ","
       << static_cast<int>( flag::blue ) << '\n';
  //codesnippet end
  
#ifdef __cpp_lib_to_underlying
  //codesnippet enumunderlying
#include <utility>
  enum class flag : unsigned int { red,white,blue };
  // but we still need to cast them
  cout << std::to_underlying( flag::red ) << ","
       << std::to_underlying( flag::white ) << ","
       << std::to_underlying( flag::blue ) << '\n';
  //codesnippet end
#endif

  
  return 0;
}
