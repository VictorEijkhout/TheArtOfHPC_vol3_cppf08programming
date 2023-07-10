/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** ortho.cxx : numerical problems in orthogaonlity
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <cmath>

struct point {
  double x; double y;
};

struct point rotate( struct point v, double alpha ) {
  double x = v.x, y = v.y;
 struct point w{ cos(alpha)*x - sin(alpha)*y, sin(alpha)*x + cos(alpha)*y };
 return w;
}

double inner_product( struct point v, struct point w ) {
  return v.x * w.x + v.y * w.y;
}

void display( struct point v ) {
  cout << "(" << v.x << "," << v.y << ")" << '\n';
}

double pi = std::atan( static_cast<double>(1) ) * 4;

int main() {

  cout << "Up" << '\n';
  {
    struct point right{1.,0.};
    struct point up = rotate(right,pi/2);
    cout << "vertical: ";
    display(up);
  }
  cout << "up\n" << '\n';

  cout << "Dot" << '\n';
  {
    for (int attempt=0; attempt<6; ++attempt) {
      struct point v{1.5,static_cast<double>(attempt)};
      struct point w = rotate(v,pi/2);
      //struct point w = rotate( rotate( rotate(v,pi/2), pi/2 ), pi/2 );
      double dot = inner_product(v,w);
      if (dot==0.) 
	cout << "inner product " << dot << " is indeed zero" << '\n';
      else if (dot>0)
	cout << "hm. positive inner product " << dot << '\n';
      else
	cout << "Reall? Negative inner product" << dot << '\n';
    }
  }
  cout << "dot\n" << '\n';

  cout << "Trick" << '\n';
  {
    struct point v{1.,1.},w{1.e-18,1.e-18};
    cout << "Points:" << '\n';
    display(v); display(w);
    cout << "dot product: " << inner_product(v,w) << '\n';
  }
  cout << "trick\n" << '\n';

  return 0;
}

