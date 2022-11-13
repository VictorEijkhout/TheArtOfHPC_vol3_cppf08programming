/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** range.cxx : C++20 ranges
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

#include <range/v3/all.hpp>

#define N 100000

int main()
{

  std::random_device r;
  std::default_random_engine generator{r()};
  std::uniform_real_distribution<double> distribution(0.,1.);

  using namespace ranges::views;
  
  vector<double> x(N),y(N);
  vector<double> x2,y2;
  vector<double> d2(N);

  int in_circle{0};
  if (false) {

    for ( auto& xi : x )
      xi = distribution(generator);
    for ( auto& yi : y )
      yi = distribution(generator);

    for ( int i=0; i<x.size(); i++ )
      x2[i] = x[i]*x[i];
    for ( int i=0; i<y.size(); i++ )
      y2[i] = y[i]*y[i];

    x2 = x | transform( [] ( auto e ) { return e*e; } ) | ranges::to_vector;
    y2 = y | transform( [] ( auto e ) { return e*e; } ) | ranges::to_vector;

    for ( int i=0; i<x.size(); i++ )
      d2[i] = x2[i] + y2[i];

    for ( auto d : d2 )
      if (d<1.) in_circle++;

  } else {

    x2 = x
      | transform( [&] ( auto e ) { return distribution(generator); } )
      | transform( [] ( auto e ) { return e*e; } )
      | ranges::to_vector;
    y2 = y
      | transform( [&] ( auto e ) { return distribution(generator); } )
      | transform( [] ( auto e ) { return e*e; } )
      | ranges::to_vector;
    for ( auto [xv,yv,dv] : zip(x2,y2,d2) )
      dv = xv+yv;
    std::for_each( d2.begin(),d2.end(),
		   [&in_circle] ( auto x ) { if (x<1.) in_circle++; }
		   );

  }

  cout << 4 * static_cast<double>(in_circle) / N << '\n';

  return 0;
}
