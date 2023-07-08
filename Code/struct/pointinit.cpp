/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-9 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pointinit.cxx : 
 ****
 ****************************************************************/

int main() {

  //codesnippet pointinit
  struct Point_a { double x; double y; } ;

  // initialization when you create the variable:
  struct Point_a x_a = {1.5,2.6};
  //codesnippet end

  //codesnippet pointinit14
  // initialization done in the structure definition:
  struct Point_b { double x=0; double y=0; } ;

  struct Point_b x_b;
  // legal since 14: ILLEGAL:
  x_b = {3.7, 4.8};
  // always legal
  x_b.x = 3.7; x_b.y = 4.8;
  //codesnippet end
  
  return 0;
}

