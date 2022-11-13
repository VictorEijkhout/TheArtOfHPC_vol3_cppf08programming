/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** matrix12.cxx : matrix 1/2D storage
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include <chrono>

class Matrix1 {
private:
  vector<vector<double>> elements;
public:
  Matrix1(int m,int n) {
    elements =
      vector<vector<double>>(m,vector<double>(n));
  }
  int m() { return elements.size(); };
  int n() { return elements.front().size(); };
  void set(int i,int j,double v) {
    elements[i][j] = v;
  };
  void add(int i,int j,double v) {
    elements[i][j] += v;
  };
  double get(int i,int j) {
    return elements[i][j];
  };
  void set(double v) {
    for ( auto& row : elements )
      for ( auto& e : row )
	e = v;
  };
  double totalsum() {
    double s=0;
    for ( auto row : elements )
      for ( auto e : row )
	s += e;
    return s;
  };
};

class Matrix2 {
private:
  int _m,_n;
  vector<double> elements;
public:
  Matrix2(int m,int n)
    : _m(n),_n(n),
      elements( vector<double>(m*n) ) {};
  int m() { return _m; };
  int n() { return _n; };
  void set(int i,int j,double v) {
    elements[i*_n+j] = v;
  };
  void add(int i,int j,double v) {
    elements[i*_n+j] += v;
  };
  double get(int i,int j) {
    return elements[i*_n+j];
  };
  void set(double v) {
    for ( auto& e : elements )
      e = v;
  };
  double totalsum() {
    double s=0;
    for ( auto e : elements )
      s += e;
    return s;
  };
};

#define NEXPT 10

int main() {

    using clock = std::chrono::high_resolution_clock;
    clock::time_point point;

    int m=5000, n=5000;

    /*
     * Prime the memory system
     */
    {
      Matrix1 matrix1(m,n);
      Matrix2 matrix2(m,n);
      cout << "Memory needed: " << 1.e-9 * sizeof(double)*matrix1.m()*matrix1.n() << "Gbyte\n";
      cout << ".. just checking: " << matrix1.totalsum() << '\n';
      cout << ".. just checking: " << matrix2.totalsum() << '\n';
      // for ( int j=0; j<matrix1.n(); j++ )
      // 	for ( int i=0; i<matrix1.m(); i++ ) {
      // 	  matrix1.add(i,j,i+j);
      // 	  matrix2.add(i,j,i+j);
      // 	}
      cout << ".. just checking: " << matrix1.totalsum() << '\n';
      cout << ".. just checking: " << matrix2.totalsum() << '\n';
    }

    /* 
     * Now for the actual tests
     */

    {
      Matrix1 matrix(m,n);
      cout << "Matrix vector-of-vector by row:\n";
      point = clock::now();
      for (int iexp=0; iexp<NEXPT; iexp++)
	for ( int i=0; i<matrix.m(); i++ )
	  for ( int j=0; j<matrix.n(); j++ )
	    matrix.add(i,j,i+j);
      auto duration = clock::now()-point;
      auto nanoseconds_duration =
	std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
      cout << "Time in msec: "
	   << static_cast<int>( nanoseconds_duration.count()*1.e-6 ) << '\n';
      cout << ".. just checking: " << matrix.totalsum() << '\n';
    }

    {
      Matrix1 matrix(m,n);
      cout << "Matrix vector-of-vector by col:\n";
      point = clock::now();
      for (int iexp=0; iexp<NEXPT; iexp++)
	for ( int j=0; j<matrix.n(); j++ )
	  for ( int i=0; i<matrix.m(); i++ )
	    matrix.add(i,j,i+j);
      auto duration = clock::now()-point;
      auto nanoseconds_duration =
	std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
      cout << "Time in msec: "
	   << static_cast<int>( nanoseconds_duration.count()*1.e-6 ) << '\n';
      cout << ".. just checking: " << matrix.totalsum() << '\n';
    }

    {
      Matrix2 matrix(m,n);
      cout << "Matrix vector-of-double by row:\n";
      point = clock::now();
      for (int iexp=0; iexp<NEXPT; iexp++)
	for ( int i=0; i<matrix.m(); i++ )
	  for ( int j=0; j<matrix.n(); j++ )
	    matrix.add(i,j,i+j);
      auto duration = clock::now()-point;
      auto nanoseconds_duration =
	std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
      cout << "Time in msec: "
	   << static_cast<int>( nanoseconds_duration.count()*1.e-6 ) << '\n';
      cout << ".. just checking: " << matrix.totalsum() << '\n';
    }

    {
      Matrix2 matrix(m,n);
      cout << "Matrix vector-of-double by col:\n";
      point = clock::now();
      for (int iexp=0; iexp<NEXPT; iexp++)
	for ( int j=0; j<matrix.n(); j++ )
	  for ( int i=0; i<matrix.m(); i++ )
	    matrix.add(i,j,i+j);
      auto duration = clock::now()-point;
      auto nanoseconds_duration =
	std::chrono::duration_cast<std::chrono::nanoseconds>(duration);
      cout << "Time in msec: "
	   << static_cast<int>( nanoseconds_duration.count()*1.e-6 ) << '\n';
      cout << ".. just checking: " << matrix.totalsum() << '\n';
    }

  return 0;
}
