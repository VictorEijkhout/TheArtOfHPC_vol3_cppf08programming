/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2020-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** ml.hpp : neural net headers
 ****
 ****************************************************************/

#include <string>
#include <vector>

/****
 **** Data vector
 ****/

class network_layer; // forward definition

class data_vector {
private:
  std::vector<float> coefficients;
public:
  data_vector(int,float=0.);
  data_vector( std::vector<float> );
  int size() const;
  float  at(int) const;
  float& at(int);
  std::string as_string() const;
  void limit();
  void copy_from( const data_vector& );
  void copy_from( const network_layer& );
  void addto( const data_vector&,float=1. );
  float distance(const data_vector &) const;

  /*
   * ranging over data:
   */
private:
  int seek{0};
public:
  data_vector &begin(); data_vector &end();
  bool operator!=( const data_vector &test ) const;
  void operator++(); float &operator*();
};

class matrix {
private:
  int m{0},n{0};
  std::vector<float> coefficients;
public:
  matrix(int,int,float=0.);
  void rank1add( const data_vector &ivec,const data_vector &jvec,float=1. );
  void mult(const data_vector&,data_vector&);
  void multt(const data_vector&,data_vector&);
};

/****
 **** Network layer
 ****/

class network_layer {
private:
  int level{-1},nin{0},nout{0};
  matrix coefficients;
  data_vector bias,input,intermediate,output,delta;
  bool trace{false};
  float learning_rate{.5};
public:
  network_layer(int,int,int,float=0.,float=0.);
  const auto &outvector() const { return output; };
  const auto &deltavector() const { return delta; };
  void multiply( const data_vector&,data_vector&, bool=false);
  void activate( const data_vector&,data_vector& );
  void apply(const data_vector&,bool=false);
  void update();
  void set_learning_rate( float rate ) { learning_rate = rate; };
  void topdelta( const data_vector&,bool=false );
};

/****
 **** Network
 ****/

class network {
private :
  std::vector<network_layer> layers;
  //std::vector<data_vector> intermediates,deltas;
  float learning_rate{.1};
public:
  network( std::vector<int> );
  int depth() const;
  float cost(const data_vector&,const data_vector&) const;
  void apply(const data_vector&,data_vector&,bool=false);
  void backpass(const data_vector&,const data_vector&,const data_vector&,
		bool=false);
  void set_learning_rate( float rate ) {
    for ( auto &l : layers )
      l.set_learning_rate(rate);
  };
};

/*
 * Auxiliaries
 */
void diff( const data_vector&,const data_vector&, data_vector& );
