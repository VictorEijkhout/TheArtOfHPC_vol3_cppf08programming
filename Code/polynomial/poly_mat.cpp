/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
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

#include <algorithm>
using std::for_each;

class mat {
private:
  double a[2][2];
public:
  mat( double x ) {
    a[0][0] = x; a[1][1] = x;
  };
  mat operator+( const mat& other ) const {
    mat sum(0.);
    sum.a[0][0] = a[0][0] + other.a[0][0];
    return sum;
  };
  void operator+=( const mat& other ) {
    a[0][0] += other.a[0][0];
  };
  mat operator*( const mat& other ) const {
    mat sum(0.);
    sum.a[0][0] = a[0][0] * other.a[0][0];
    return sum;
  };
  void operator*=( const mat& other ) {
    a[0][0] *= other.a[0][0];
  };
  double value() const { return a[0][0]; };
};

std::ostream &operator<<( std::ostream &os,const mat &m ) {
  os << m.value();
  return os;
};

//codesnippet polymatclass
template< typename Scalar >
class polynomial {
private:
  vector<Scalar> coefficients;
public:
  polynomial( vector<Scalar> c )
    : coefficients(c) {};
  int degree() const { return coefficients.size()-1; };
  // 5 x^2 + 4 x + 3 = 5 x + 4 x + 3
  Scalar eval( Scalar x ) const {
    Scalar y{0.};
    for_each(coefficients.rbegin(),coefficients.rend(),
	     [x,&y] (Scalar c) { y *= x; y += c; } );
    return y;
  };
  //codesnippet end
  Scalar operator()(Scalar x) const { return eval(x); };
  polynomial operator+( const polynomial &other ) const {
    vector<Scalar> newcoeff( std::max(degree()+1,other.degree()+1),0. );
    int iloc{0};
    for ( auto c : coefficients )
      newcoeff.at(iloc++) = c;
    iloc = 0;
    for ( auto c : other.coefficients ) {
      newcoeff.at(iloc) += c;
      iloc++;
    }
    return polynomial( newcoeff );
  };
  // string render() const {
  //   stringstream r;
  //   r << "[";
  //   for ( auto c : coefficients )
  //     r << c << ",";
  //   r << "]";
  //   return r.str();
  // };
};

int main() {

  {
    //codesnippet temppolydouble
    polynomial<double> x2p2( {2., 0., 1.} );
    for ( auto x : {1., 2., 3.} ) {
      auto y = x2p2(x);
      cout << "Second power of x=" << x << " plus 2 gives y=" << y << '\n';
    }
    //codesnippet end
    polynomial<double> x2( {0., 2.} );
    polynomial<double> x2x2 = x2p2 + x2; // x^2 + 2x + 2
    //  cout << "sum polynomnial: " << x2x2.render() << '\n';
    for ( auto x : {1., 2., 3.} ) {
      auto y = x2x2(x);
      cout << "x^2 + 2x + 2 for x=" << x << " y=" << y << '\n';
    }
  }

  {
    //codesnippet temppolymat
    polynomial<mat> x2p2( {2., 0., 1.} );
    for ( auto x : {1., 2., 3.} ) {
      auto y = x2p2(x);
      cout << "Second power of x=" << x << " plus 2 gives y=" << y << '\n';
    }
    //codesnippet end
    polynomial<mat> x2( {0., 2.} );
    polynomial<mat> x2x2 = x2p2 + x2; // x^2 + 2x + 2
    //  cout << "sum polynomnial: " << x2x2.render() << '\n';
    for ( auto x : {1., 2., 3.} ) {
      auto y = x2x2(x);
      cout << "x^2 + 2x + 2 for x=" << x << " y=" << y << '\n';
    }
  }

  return 0;
}
