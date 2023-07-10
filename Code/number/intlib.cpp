// -*- c++ -*-
/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** intlib.cxx : header file for the number theory project
 ****
 **** division algorithm by Knuth, explained in:
 **** https://janmr.com/blog/2014/04/basic-multiple-precision-long-division/
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <tuple>
using std::pair;
#include <vector>
using std::vector;

#include <cassert>

#include "intlib.hpp"

/*
 * Constructors
 */
template<int base>
BigInt<base>::BigInt( int init ) {
  while ( init>0 ) {
    int d = init%base;
    _digits.push_back( d );
    init = init / base;
  };
};
template<int base>
BigInt<base>::BigInt( vector<int> digits ) : _digits(digits) {};

/*
 * Basic digit twiddling
 */
template<int base>
int BigInt<base>::ndigits() const { return _digits.size(); };

template<int base>
int BigInt<base>::digitbase() const { return base; };

template<int base>
int BigInt<base>::digit(int i) const { return _digits.at(i); };
template<int base>
int& BigInt<base>::digit(int i) { return _digits.at(i); };
template<int base>
int BigInt<base>::leading_digit( int from_back) const {
  if (_digits.empty()) return 0;
  else return _digits.at( _digits.size()-1-from_back );
};
template<int base>
void BigInt<base>::set_leading_digit( int i ) { _digits.push_back(i); };

template<int base>
void BigInt<base>::shift( int n ) {
  for ( int i=0; i<n; ++i)
    _digits.insert( _digits.begin(),0 );
};
template<int base>
void BigInt<base>::decr() {
  if (_digits.at(0)==0)
    throw( "unimplemented case" );
  else
    _digits.at(0)--;
};
template<int base>
int BigInt<base>::numeric() const {
  int result{0};
  for ( auto d=_digits.rbegin(); d!=_digits.rend(); ++d )
    result = base * result + *d;
  return result;
};

/*
 * Operators to make this look like math
 */
template<int base>
bool BigInt<base>::operator==(int compare) const {
  return numeric()==compare;
};

template<int base>
bool BigInt<base>::operator<( const BigInt& other ) const {
  return ndigits()<other.ndigits() or
    ( ndigits()==other.ndigits() and leading_digit()<other.leading_digit() );
};

template<int base>
BigInt<base> BigInt<base>::operator+( const BigInt& other ) const {
  if ( *this < other )
    return other+(*this);
  else {
    BigInt<base> result( *this );
    int carry = 0;
    for ( int id=0; id<other.ndigits(); ++id ) {
      auto sumdigit = digit(id)+other.digit(id)+carry;
      carry = sumdigit/base;
      sumdigit = sumdigit%base;
      result.digit(id) = sumdigit;
    }
    if (carry>0)
      result.set_leading_digit(carry);
    return result;
  }
};

//! Increase digit id by borrowing from higher digits
template<int base>
void BigInt<base>::borrow( int id ) {
  assert( id< ndigits()-1 );
  if ( _digits.at(id+1)==0 )
    borrow(id+1);
  _digits.at(id+1)--;
  _digits.at(id) += base;
};

template<int base>
BigInt<base> BigInt<base>::operator-( const BigInt& other ) const {
  if ( *this < other )
    throw("subtraction would yield negative");
  else {
    BigInt<base> result( *this );
    for ( int id=0; id<result.ndigits(); ++id ) {
      if (id>=other.ndigits())
	break;
      if (result.digit(id)<other.digit(id)) {
	result.borrow(id);
      }
      result.digit(id) -= other.digit(id);
      // cout << "digit" << id << ": " << result.digit(id) << '\n';
    }
    while (result.back()==0)
      result.pop();
    return result;
  }
};
template<int base>
BigInt<base> BigInt<base>::operator*( int mult ) const {
  if ( mult==base ) {
    BigInt<base> result(*this); result.shift(1);
    return result;
  } else {
    BigInt<base> result;
    int carry = 0;
    for ( auto d : _digits ) {
      auto proddigit = mult * d + carry;
      carry = proddigit / base;
      result.set_leading_digit( proddigit % base );
    }
    if (carry>0)
      result.set_leading_digit(carry);
    return result;
  }
};
template<int base>
BigInt<base> BigInt<base>::operator*( const BigInt& other ) const {
  BigInt<base> result;
  for ( auto d : _digits ) {
    BigInt<base> line = other * d * base;
    result = result+line;
  }
  return result;
};

/*
 * Dividion algorithm
 * see:
 * https://janmr.com/blog/2014/04/basic-multiple-precision-long-division/
 */

template<int base>
BigInt<base> find_qhat( BigInt<base> denom,BigInt<base> numer ) {
  int n = numer.ndigits();
  assert( denom.ndigits()==n+1 );
  assert( n>=2 );
  int
    b = base,
    numer_n1 = denom.leading_digit(1),
    denom_2 = b*denom.leading_digit() + numer_n1;
  int
    u_n2 = denom.digit(n-2),
    v_n1 = numer.digit(n-1), v_n2 = numer.digit(n-2),  
    qhat = denom_2 / v_n1,
    rhat = denom_2 % v_n1;
  if (qhat==b) {
    cout << "Unimplemented case\n"; throw("Unimplemented case");}
  while (rhat<b and qhat*v_n2>b*rhat+u_n2) {
    qhat = qhat-1; rhat = rhat + v_n1;    
  }
  return BigInt<base>(qhat);
};

template<int base>
pair<BigInt<base>,BigInt<base>> BigInt<base>::
operator/( const BigInt<base>& denom ) const {
  // L1: make leading digit big enough
  if ( denom.leading_digit() < base/2 )
    return (*this*2)/(denom*2);
  else {
    BigInt<base> numer(*this); BigInt<base> div;
    for ( int k = ndigits()-denom.ndigits(); k>0; ) {
      BigInt<base> qhat = find_qhat( numer,denom );
      if ( numer < denom*qhat ) qhat.decr();
      assert( qhat.ndigits()==1 );
      numer = numer - denom*qhat;
      div.digits().insert( /* pos: */ div.digits().begin(), /* val: */ qhat.digits().front() );
    }
    // L7: if k==0 
    return {div,div}; // CHECK ON THIS. INCOMPLETE?
  }
};

template class BigInt<10>;
template class BigInt<1000>;
