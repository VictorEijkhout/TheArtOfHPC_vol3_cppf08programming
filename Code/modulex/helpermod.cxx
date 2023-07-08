/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** fgmod.cxx : simple module
 ****
 ****************************************************************/

//codesnippet modintface
export module helper_module;
import :helper;

// exported function
export int f( int i ) {
  return g(i+1);
};
//codesnippet end
