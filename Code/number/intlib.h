// -*- c++ -*-
/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** intlib.h : header file for the number theory project
 ****
 ****************************************************************/

#include <tuple>
#include <vector>

template<int base>
class BigInt {
private:
  // static inline int _base = 1000;
  std::vector<int> _digits;
public:
  BigInt<base>() {};
  BigInt<base>( int init );
  BigInt<base>( std::vector<int> digits );
  // digit twiddling
  int digitbase() const; int ndigits() const; void borrow(int);
  int digit(int i) const; int& digit(int i) ;
  auto& digits() { return _digits; }; const auto digits() const { return _digits; };  
  //  const auto begin() const { return _digits.begin(); }; auto begin() { return _digits.begin(); };
  int leading_digit(int=0) const ; void set_leading_digit( int i ) ;
  int front() const { return _digits.front(); };
  int back() const { return _digits.back(); };
  void pop() { _digits.pop_back(); };
  void decr(); void shift( int n ) ;
  int numeric() const ;
  // operators
  bool operator==(int compare) const ;
  bool operator<( const BigInt<base>& other ) const ;
  BigInt<base> operator+( const BigInt<base>& other ) const ;
  BigInt<base> operator-( const BigInt<base>& other ) const ;
  BigInt<base> operator*( int mult ) const ;
  BigInt<base> operator*( const BigInt<base>& other ) const ;
  std::pair<BigInt<base>,BigInt<base>> operator/( const BigInt<base>& div ) const ;
};

template<int base>
BigInt<base> find_qhat( BigInt<base> denom,BigInt<base> numer );
