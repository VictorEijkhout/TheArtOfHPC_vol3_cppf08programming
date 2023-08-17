/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** except.cxx : exception example
 ****
 **** This is a bad example: cin does not use exceptions
 **** there is cin.exceptions( stuff )
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <source_location>

int main()
{

  int i=2;
  try {
    if (i>0)
      throw(i);
  } catch( ... ) {
    //codesnippet sourceloc
#if defined(__cpp_lib_source_location)
    std::source_location loc_info
      = std::source_location::current();
    cout << "Exception at line " << loc_info.line << '\n';
#else
    cout << "Exception at unknown source location\n";
#endif
    //codesnippet end
  }

  return 0;

}
