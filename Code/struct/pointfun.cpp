/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pointfun.cxx : function taking struct arguments
 ****
 ****************************************************************/

#include <cmath>

#include <iostream>
using std::cin;
using std::cout;

struct point { double x; double y; } ;

//codesnippet structpass
double distance
  ( struct point p1,
    struct point p2 )
{
  double
    d1 = p1.x-p2.x, d2 = p1.y-p2.y;
  return sqrt( d1*d1 + d2*d2 );
}
//codesnippet end

int main() {

  struct point p1 = { 1.,1. };
  cout << "Displacement x,y?";
  double dx,dy; cin >> dx >> dy; cout << '\n';

  cout << "Struct Pass" << '\n';
  //codesnippet structpass
  cout << "dx=" << dx
       << ", dy=" << dy << '\n';
  struct point p2 = { p1.x+dx,p1.y+dy };
  cout << "Distance: "
       << distance(p1,p2) << '\n';
  //codesnippet end
  cout << ".. struct pass" << '\n';

  cout << "Struct Denote" << '\n';
  {
    //codesnippet structdenote
    struct point p1{1.,2.}, p2{6.,14.};
    cout << "Distance: "
         << distance( p1,p2 )
         << '\n';
    cout << "Distance: "
         << distance( {1.,2.}, {6.,14.} )
         << '\n';
    //codesnippet end
  }
  cout << ".. struct denote" << '\n';
  
  return 0;
}

