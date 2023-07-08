/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** fgmod.cxx : simple module
 ****
 ****************************************************************/

//codesnippet modformain
export module fg_module;

// internal function
int g( int i ) { return i/2; };

// exported function
export int f( int i ) {
  return g(i+1);
};
//codesnippet end

