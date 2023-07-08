/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** fractionlib. : classes for fractions
 ****
 ****************************************************************/

#include <iostream>
using std::ostream;
#include <cmath>

using inttype = long int;

inttype gcd( inttype i,inttype j ) {
  if (i<0 or j<0)
    return gcd( std::abs(i),std::abs(j) );
  if (i>j)
    return gcd(j,i);
  else if (i==0)
    return j;
  else
    return gcd( j%i, i );
};

class Fraction {
private:
  inttype numer,denom;
public:
  Fraction(int n,int d)
    : numer(n),denom(d) {
    simplify();
  };
  void simplify() {
    auto g = gcd(numer,denom);
    numer /= g; denom /= g;
  };
  auto numerator() const { return numer; };
  auto denominator() const { return denom; };
  Fraction operator*( int mult ) {
    return Fraction( mult*numer,denom );
  };    
  Fraction operator+( Fraction other ) {
    Fraction sum(*this); // or Fraction(numer,denom);
    sum += other;
    return sum;
  };
  Fraction operator+=( Fraction other ) {
    inttype
      d1 = denom, d2=other.denom,
      n1 = numer, n2=other.numer;
    numer = n1*d2 + n2*d1; denom = d1*d2; simplify();
    return *this;
  };
  bool operator==( Fraction other ) const {
    return numer==other.numer and denom==other.denom;
  };
  bool operator!=( Fraction other ) const {
    return numer!=other.numer or denom!=other.denom;
  };
};

ostream& operator<<(ostream& oldstream,const Fraction& f) {
  oldstream << f.numerator() << "/" << f.denominator();
  return oldstream;
}

Fraction FareyAvg( Fraction f1,Fraction f2 ) {
  return Fraction( f1.numerator()+f2.numerator(),f1.denominator()+f2.denominator() );
};

class FareySequence {
public:
  int level;
  vector<Fraction> fractions;
public:
  FareySequence() {
    level = 1;
    fractions = { Fraction(0,1),Fraction(1,1) };
  };
  FareySequence( int level, vector<Fraction> fractions )
    : level(level),fractions(fractions) {};
  FareySequence next() {
    auto nextlevel = level+1;
    vector<Fraction> nextfractions;
    return FareySequence( nextlevel,nextfractions );
  }
};

ostream& operator<<(ostream& oldstream,const FareySequence& s) {
  for ( auto f : s.fractions ) 
    oldstream << "( " << s << " ), ";
  return oldstream;
}

