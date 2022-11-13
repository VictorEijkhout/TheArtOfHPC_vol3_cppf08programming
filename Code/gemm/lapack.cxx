/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-9 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** lapack.cxx : dense matrices ;with variant<vector,span>
 **** WRONG unfinished
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <limits>
using std::numeric_limits;

#include <vector>
using std::vector;

#include <chrono>
using namespace std::chrono;

#include <variant>
using std::variant;
using std::get;
using std::get_if;

#include "gsl/gsl-lite.hpp"
using gsl::span;

#ifdef CBLAS
#include <cblas.h>
#else
// dgemm: TRANSA, TRANSB, M, N, K, ALPHA, A, LDA, B, LDB, BETA, C, LDC
extern "C" {
void dgemm_(char*,char*,int*,int*,int*,
	    double*,double*,int*,
	    double*,int*,
	    double*,double*,int*);
}
#endif

class Matrix {
private:
  int m,n,lda;
  variant< vector<double>, span<double> > data;
public:
  Matrix(int m,int n,double v=0)
    : m(m),n(n),lda(m),
      data( vector<double>(m*n,v) ) { cout << "alloc" << '\n'; };
  Matrix(int m,int n,int lda,double *data)
    : m(m),n(n),lda(lda),
      data( span<double>(data,lda*n) ) { cout << "span" << '\n'; };
  double& at(int i,int j) { // zero-based
    if ( auto matrix_data = get_if<vector<double>>( &data ) ; matrix_data )
      return ( matrix_data )->at(j*lda+i);
    else
      return ( get_if<span<double>>( &data ) )->at(j*lda+i);
  };
#define AT(i,j,m,n,lda) (i)+(j)*(lda)
  double at(int i,int j) const { // zero-based
    if ( auto matrix_data = get_if<vector<double>>( &data ) ; matrix_data )
      return ( matrix_data )->at(j*lda+i);
    else
      return ( get_if<span<double>>( &data ) )->at(j*lda+i);
  };
  auto get_double_data() {
    double *adata;
    if ( auto matrix_data = get_if<vector<double>>( &data ) ; matrix_data )
      adata = ( matrix_data )->data();
    else
      adata = ( get_if<span<double>>( &data ) )->data();
    return adata;
  };
  Matrix Left(int j) {
    auto adata = get_double_data();
    return Matrix(m,j,lda,adata);
  };
  Matrix Right(int j) {
    auto adata = get_double_data();
    return Matrix(m,n-j,lda,adata+j*lda);
  };
  Matrix Top(int i) {
    auto adata = get_double_data();
    return Matrix(i,n,lda,adata);
  };
  Matrix Bot(int i) {
    auto adata = get_double_data();
    return Matrix(m-i,n,lda,adata+i);
  };
  Matrix operator+( Matrix other ) const {
    if (other.m!=m or other.n!=n) {
      cout << "Operator+: incompatible dimensions" << '\n';
      throw(1); }
    Matrix out(m,n);
    for (int j=0; j<n; j++)
      for (int i=0; i<m; i++)
	out.at(i,j) = at(i,j)+other.at(i,j);
    return out;
  };
  auto min() {
    auto matdata = get_double_data();
    auto mn = numeric_limits<double>::max();
    for (int j=0; j<n; j++)
      for (int i=0; i<m; i++) {
	double v;
#ifdef DEBUG
	try {
	  v = at(i,j);
	} catch (std::out_of_range e) {
	  cout << "min out of range: " << i << "," << j << '\n';
	  throw(1); }
#else
	v = matdata[ i+j*lda ];
#endif
	if (v<mn) mn = v;
      }
    return mn;
  };
  auto max() {
    auto matdata = get_double_data();
    auto mx  = numeric_limits<double>::min();
    for (int j=0; j<n; j++)
      for (int i=0; i<m; i++) {
	double v;
#ifdef DEBUG
	try {
	  v = at(i,j);
	} catch (std::out_of_range e) {
	  cout << "max out of range: " << i << "," << j << '\n';
	  throw(1); }
#else
	v = matdata[ i+j*lda ];
#endif
	if (v>mx) mx = v;
      }
    return mx;
  };
  void MatMult( Matrix& other,Matrix& out ) {
    if (n!=other.m || m!=out.m || other.n!=out.n) {
      cout << "MatMult: incompatible dimensions" << '\n';
      throw(1); }
    double alpha = 1., beta = 0.;
    auto adata = get_double_data();
    auto bdata = other.get_double_data();
    auto cdata = out.get_double_data();
#ifdef CBLAS
    cblas_dgemm
      ( CblasColMajor, CblasNoTrans, CblasNoTrans,
	m,other.n,n, alpha,adata,lda,
	bdata,other.lda,
	beta,cdata,out.lda);
#else
    for (int i=0; i<out.m; i++) {
      for (int j=0; j<out.n; j++) {
    	double s{0};
    	for (int k=0; k<n; k++) {
#ifdef DEBUG
	  s += at(i,k) * other.at(k,j);
#else
    	  s += adata[ AT(i,k, m,n,lda) ] * bdata[ AT(k,j, other.m,other.n,other.lda) ];
#endif
	}
#ifdef DEBUG
	out.at(i,j) = s;
#else
    	cdata[ AT(i,j, out.m,out.n,out.lda) ] = s;
#endif
      }
    }
    // { char transa='n',transb='n';
    //   dgemm_(  &transa,&transb, &m,&other.n,&n,
    // 	       &alpha,adata,&lda,
    // 	       bdata,&other.lda,
    // 	       &beta,cdata,&out.lda );
    // }
#endif
  };
  Matrix operator*( Matrix other ) {
    if (n!=other.m) {
      cout << "Operator+: incompatible dimensions" << '\n';
      throw(1); }
    Matrix out(m,other.n);
    double alpha = 1., beta = 0.;
    auto adata = get_double_data();
    auto bdata = other.get_double_data();
    auto cdata = out.get_double_data();
#ifdef CBLAS
    cblas_dgemm
      ( CblasColMajor, CblasNoTrans, CblasNoTrans,
	m,other.n,n, alpha,adata,lda,
	bdata,other.lda,
	beta,cdata,out.lda);
#else
    { char transa='n',transb='n';
      dgemm_(  &transa,&transb, &m,&other.n,&n,
	       &alpha,adata,&lda,
	       bdata,&other.lda,
	       &beta,cdata,&out.lda );
    }
#endif
    // for (int i=0; i<out.m; i++) {
    //   for (int j=0; j<out.n; j++) {
    // 	double s{0};
    // 	for (int k=0; k<n; k++)
    // 	  s += at(i,k) * other.at(k,j);
    // 	out.at(i,j) = s;
    //   }
    // }
    return out;
  };
  void print() const {
    for (int i=0; i<m; i++) {
      for (int j=0; j<n; j++)
	cout << at(i,j) << " ";
      cout << '\n';
    }
  };
};

int main() {

  Matrix one(2,3,1.),two(2,3,2.);
  Matrix three( one+two );
  three.print();

  Matrix onet(3,4,1.);
  for (int i=0; i<3; i++)
    for (int j=0; j<4; j++)
      onet.at(i,j) = j+1;

  cout << "\n2x4:" << '\n';
  Matrix threes( one*onet );
  threes.print();

  cout << "\nleft submatrix:" << '\n';
  auto threeL = threes.Left(2);
  threeL.print();

  cout << "\nright submatrix:" << '\n';
  auto threeR = threes.Right(2);
  threeR.print();

  cout << "\ntop submatrix:" << '\n';
  auto threeT = threes.Top(1);
  threeT.print();

  cout << "\nbot submatrix:" << '\n';
  auto threeB = threes.Bot(1);
  threeB.print();

  cout << "\nMatMult:" << '\n';
  {
    int M = 1024, N = 1024;
    Matrix A(M,N,1.),B(M,N,2.),C(M,N);
    {
      auto start_time = high_resolution_clock::now();
      A.MatMult(B,C);
      auto end_time = high_resolution_clock::now();
      auto duration = duration_cast<milliseconds>(end_time - start_time).count();
      cout << "product took: " << duration << " milliseconds" << '\n';
      cout << "checking:" << '\n';
      auto min = C.min(), max = C.max();
      cout << "C range: " << min << "--" << max << '\n';
    }
    {
      auto start_time = high_resolution_clock::now();
      A.RecursiveMatMult(B,C);
      auto end_time = high_resolution_clock::now();
      auto duration = duration_cast<milliseconds>(end_time - start_time).count();
      cout << "recursive product took: " << duration << " milliseconds" << '\n';
      cout << "checking:" << '\n';
      auto min = C.min(), max = C.max();
      cout << "C range: " << min << "--" << max << '\n';
    }
  }

  return 0;
}
