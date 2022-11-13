/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** printbits.c : printing out bit patterns
 ****
 ****************************************************************/

#include <sstream>

//codesnippet cprintbits
std::string printBits(size_t const size, void const * const ptr)
{
  std::stringstream ss;
  unsigned char *b = (unsigned char*) ptr;
  unsigned char byte;
  int i, j;

  for (i=size-1;i>=0;i--)
    for (j=7;j>=0;j--) {
      byte = (b[i] >> j) & 1;
      ss << byte ; // originally: printf("%u", byte);
    }
  return ss.str();
}
//codesnippet end
