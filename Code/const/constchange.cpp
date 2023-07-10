/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** constchange.cxx : attempt to change const => compiler error
 ****
 ****************************************************************/

//codesnippet constchange
void f(const int i) {
  ++i;
}
//codesnippet end

int main() {

  return 0;
}
