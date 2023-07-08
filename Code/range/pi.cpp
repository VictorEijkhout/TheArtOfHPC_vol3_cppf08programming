/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** pi.cxx : C++20 ranges for \pi calculation
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <vector>
using std::vector;

#include <algorithm>

//#include <ranges>
// we need zip
#include <range/v3/all.hpp>
#ifdef RANGES_V3_ALL_HPP
namespace rng = ranges;
#else
namespace rng = std::ranges;
#endif

#define N 100000

int main()
{

  std::random_device r;
  std::default_random_engine generator{r()};
  std::uniform_real_distribution<double> distribution(0.,1.);

  vector<double> x(N),y(N);
  vector<double> x2,y2;
  vector<double> d2(N);

  int in_circle{0};

  x2 = x
    | rng::views::transform( [&] ( auto e ) { return distribution(generator); } )
    | rng::views::transform( [] ( auto e ) { return e*e; } )
    // | rng::to_vector
    ;
  y2 = y
    | rng::views::transform( [&] ( auto e ) { return distribution(generator); } )
    | rng::views::transform( [] ( auto e ) { return e*e; } )
    // | rng::to_vector
    ;
  auto d2r = d2
    | rng::views::filter( [] ( auto e ) { return true; } )
    ;
  for ( auto [xv,yv,dv] : rng::views::zip(x2,y2,d2r) )
    dv = xv+yv;
  std::for_each( d2.begin(),d2.end(),
		 [&in_circle] ( auto x ) { if (x<1.) in_circle++; }
		 );

  cout << 4 * static_cast<double>(in_circle) / N << '\n';

  return 0;
}

#if 0

  if (false) {

    for ( auto& xi : x )
      xi = distribution(generator);
    for ( auto& yi : y )
      yi = distribution(generator);

    for ( int i=0; i<x.size(); i++ )
      x2[i] = x[i]*x[i];
    for ( int i=0; i<y.size(); i++ )
      y2[i] = y[i]*y[i];

    x2 = x | rng::views::transform( [] ( auto e ) { return e*e; } ) | rng::to_vector;
    y2 = y | rng::views::transform( [] ( auto e ) { return e*e; } ) | rng::to_vector;

    for ( int i=0; i<x.size(); i++ )
      d2[i] = x2[i] + y2[i];

    for ( auto d : d2 )
      if (d<1.) in_circle++;

  } else {

#endif
    
