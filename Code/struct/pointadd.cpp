/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pointadd.cxx : function returning struct
 ****
 ****************************************************************/

#include <cmath>

#include <iostream>
using std::cin;
using std::cout;

struct point { double x; double y; } ;

//codesnippet structreturn
struct point point_add
      ( struct point p1,
        struct point p2 ) {
   struct point p_add =
     {p1.x+p2.x,p1.y+p2.y};
   return p_add;
};
//codesnippet end

int main() {

  struct point p1,p2,v3;

  p1.x = 1.; p1.y = 1.;
  p2 = {4.,5.};

//codesnippet structreturn
  v3 = point_add(p1,p2);
  cout << "Added: " <<
    v3.x << "," << v3.y << '\n';
//codesnippet end
  
  return 0;
}

