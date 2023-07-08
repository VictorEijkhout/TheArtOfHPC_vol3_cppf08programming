/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** fgmod.cxx : simple module
 ****
 ****************************************************************/

//codesnippet modhelper
// implementation unit, nothing exported
module helper_module:helper;
// internal function
int g( int i ) { return i/2; };
//codesnippet end

