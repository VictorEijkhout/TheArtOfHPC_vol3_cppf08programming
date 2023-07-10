/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2020-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** mllib.cpp : neural net library
 ****
 ****************************************************************/

#include "ml.hpp"

#include <iostream>
using std::cout;
#include <sstream>
using std::stringstream;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <cmath>
#include <cassert>

/*
 * One data vector
 */
data_vector::data_vector(int n,float init)
  : coefficients( vector<float>(n,init) ) {
};

data_vector::data_vector( vector<float> coefficients )
  : coefficients(coefficients) {
};

int data_vector::size() const { return coefficients.size(); };
float  data_vector::at(int i) const { return coefficients.at(i); };
float& data_vector::at(int i)       { return coefficients.at(i); };
void data_vector::limit() { // maybe for future use
  for ( auto &e : coefficients )
    e = .00;
};

void data_vector::copy_from( const data_vector &other ) {
  assert( size()==other.size() );
  for (int i=0; i<size(); ++i)
    coefficients.at(i) = other.at(i);
};

void data_vector::copy_from( const network_layer &other ) {
  assert( size()==other.outvector().size() );
  for (int i=0; i<size(); ++i)
    coefficients.at(i) = other.outvector().at(i);
};

void data_vector::addto( const data_vector &add,float coeff ) {
  assert( size()==add.size() );
  for (int i=0; i<size(); ++i)
    coefficients.at(i) += coeff * add.at(i);
};

float data_vector::distance(const data_vector &other) const {
  assert(size()==other.size());
  float s{0.};
  for (int i=0; i<size(); ++i) {
    auto d = at(i)-other.at(i);
    s += d*d;
  }
  return s;
};

string data_vector::as_string() const {
  stringstream res;
  for ( auto e : coefficients )
    res << e << " ";
  return res.str();
};

data_vector &data_vector::begin() { seek = 0; return *this; };
data_vector &data_vector::end()   { seek = coefficients.size(); return *this; };
bool data_vector::operator!=( const data_vector &test ) const {
  return seek<test.seek; };
void data_vector::operator++() { seek++; };
float &data_vector::operator*() { return coefficients.at(seek); };

matrix::matrix( int m,int n,float init)
  : coefficients( vector<float>(m*n,init) ),m(m),n(n) {
};

void matrix::mult(const data_vector &in,data_vector &out) {
  assert( in.size()==n );
  assert( out.size()==m );
  for (int i=0; i<m; ++i) {
    float s{0.};
    for (int j=0; j<n; ++j)
      s += coefficients.at( i*n + j ) * in.at(j);
    out.at(i) = s;
  }
};

void matrix::multt(const data_vector &in,data_vector &out) {
  assert( in.size()==m );
  assert( out.size()==n );
  for (int j=0; j<n; ++j) {
    float s{0.};
    for (int i=0; i<m; ++i)
      s += coefficients.at( i*n + j ) * in.at(i);
    out.at(j) = s;
  }
};

/*
 * One network layer
 */

network_layer::network_layer(int level,int insize,int outsize,float init,float binit)
  : nin(insize),nout(outsize),level(level),
    coefficients( matrix(outsize,insize,init) ),
    input       ( data_vector(insize) ),
    output      ( data_vector(outsize) ),
    delta       ( data_vector(outsize) ),
    bias        ( data_vector(outsize,binit) ),
    intermediate( data_vector(outsize) ) {
};
 
void network_layer::multiply( const data_vector &input,data_vector &intermediate, bool trace) {
  coefficients.mult(input,intermediate);
  intermediate.addto(bias);
  if (trace)
    cout << "multiply " << input.as_string()
	 << " giving " << intermediate.as_string() << '\n';
};

void network_layer::activate( const data_vector &intermediate,data_vector &output) {
  assert( intermediate.size()==output.size() );
  for (int i=0; i<output.size(); ++i) {
    const auto &d = intermediate.at(i);
    output.at(i) = 1./ (1+exp(-d));
  }
};

void network_layer::apply(const data_vector &indata,bool trace) {
  input.copy_from(indata);
  multiply(input,intermediate,trace);
  activate(intermediate,output);
  if (trace) {
    cout << "Layer " << level << " input: "  << input.as_string() << '\n';
    cout << "Layer " << level << " output: " << output.as_string() << '\n';
  }
};

void matrix::rank1add( const data_vector &ivec,const data_vector &jvec,float c ) {
  assert( ivec.size()==m );
  assert( jvec.size()==n );
  for ( int i=0; i<m; ++i)
    for ( int j=0; j<n; ++j )
      coefficients.at( i*n+j ) = c * ivec.at(i) * jvec.at(j);
};

void network_layer::update() {
  bias.addto( delta, learning_rate );
  coefficients.rank1add( delta,input,learning_rate );
};

/*
 * Whole network
 */
network::network( vector<int> datasizes ) {
  for ( int level=0; level<datasizes.size()-1; ++level ) {
    auto
      insize  = datasizes.at(level),
      outsize = datasizes.at(level+1);
    layers.push_back( network_layer(level,insize,outsize,.5,.5) );
    layers.at( layers.size()-1 ).set_learning_rate(learning_rate);
  }
};

int network::depth() const {
  return layers.size();
};

float network::cost(const data_vector &u,const data_vector &v) const {
  return u.distance(v);
};

void network::apply(const data_vector &indata,data_vector &outdata,bool trace) {
  const int d = depth();
  layers.at(0).apply(indata,trace);
  for (int l=1; l<d-1; ++l) {
    layers.at(l).apply( layers.at(l-1).outvector(),trace );
  }
  outdata.copy_from( layers.at(d-1) );
};

void network_layer::topdelta( const data_vector &reference,bool trace ){
  assert(reference.size()==output.size());
  if (trace)
    cout << "constructing topdelta from intermediate: " << intermediate.as_string()
	 << ", output: " << output.as_string()
	 << ", reference: " << reference.as_string()
	 << '\n';
  for (int i=0; i<output.size(); ++i)
    delta.at(i) =
      intermediate.at(i)*(1-intermediate.at(i)) // sigma(z)
      *
      ( output.at(i)-reference.at(i) );
};

void network::backpass
   ( const data_vector &input,const data_vector &computed,const data_vector &reference,
     bool trace) {
  for (int d=depth()-1; d>=0; d--) {
    if (d==depth()-1) 
      layers.at(d).topdelta(reference,trace);
    else {
      // for (int l=d-2; l>=0; l--) {
      //   deltas.at(l).recursive_delta( deltas.at(l+1),intermediates.at(l) );
      cout << "Can not handle multiple layers right now" << '\n';
      throw(1); }
    if (trace)
      cout << "delta" << d << ": " << layers.at(d).deltavector().as_string() << '\n';
    layers.at(d).update();
  }
};

/*
 * Auxiliary functions
 */
void diff( const data_vector &in1,const data_vector &in2, data_vector &out ) {
  assert(in1.size()==in2.size());
  assert(in2.size()==out.size());
  for (int i=0; i<out.size(); ++i)
    out.at(i) = in1.at(i) - in2.at(i);
};
