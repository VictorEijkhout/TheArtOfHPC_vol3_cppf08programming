/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** poly_eval.cxx : polynomial class
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;
#include <sstream>
using std::stringstream;
#include <vector>
using std::vector;

//codesnippet polydouble
class polynomial {
private:
  vector<double> coefficients;
public:
  polynomial( vector<double> c )
    : coefficients(c) {};
  // 5 x^2 + 4 x + 3 = 5 x + 4 x + 3
  double eval( double x ) const {
    double y{0.};
    for_each(coefficients.rbegin(),coefficients.rend(),
	     [x,&y] (double c) { y *= x; y += c; } );
    return y;
  };
  double operator()(double x) const { return eval(x); };
  //codesnippet end
  polynomial operator+( const polynomial &other ) const {
    vector<double> newcoeff( std::max(degree()+1,other.degree()+1),0. );
    int iloc{0};
    for ( auto c : coefficients )
      newcoeff.at(iloc++) = c;
    iloc = 0;
    for ( auto c : other.coefficients )
      newcoeff.at(iloc++) += c;
    return polynomial( newcoeff );
  };
  int degree() const { return coefficients.size()-1; };
  string render() const {
    stringstream r;
    r << "[";
    for ( auto c : coefficients )
      r << c << ",";
    r << "]";
    return r.str();
  };
};

int main() {

  //codesnippet polydoubleapply
  polynomial x2p2( {2., 0., 1.} );
  for ( auto x : {1., 2., 3.} ) {
    auto y = x2p2(x);
    cout << "Second power of x=" << x << " plus 2 gives y=" << y << '\n';
  }
  //codesnippet end
  polynomial x2( {0., 2.} );
  polynomial x2x2 = x2p2 + x2; // x^2 + 2x + 2
  cout << "sum polynomnial: " << x2x2.render() << '\n';
  for ( auto x : {1., 2., 3.} ) {
    auto y = x2x2(x);
    cout << "x^2 + 2x + 2 for x=" << x << " y=" << y << '\n';
  }
  

  return 0;
}
