/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** dijkstra1.cxx : shortest path exploration
 ****
 ****************************************************************/

#include <algorithm>
using std::max;

#include <iostream>
using std::cin;
using std::cout;
#include <sstream>
using std::stringstream;
#include <string>
using std::string;

#include <random>
#include <tuple>
using std::tuple;
#include <vector>
using std::vector;

#include <cassert>

float chance() {
  static  std::default_random_engine static_engine{1};
  std::uniform_real_distribution<float> p(0.f,1.f);
  return p(static_engine);
};

int random_degree( int n ) {
  static  std::default_random_engine static_engine{2};
  std::uniform_int_distribution<> p(n/2,3*n/2);
  return p(static_engine);
};

int random_int( int n ) {
  static  std::default_random_engine static_engine{3};
  std::uniform_int_distribution<> p(0,n-1);
  return p(static_engine);
};

using distance = float;
const distance inf_distance=-1;

#include "levelset.cpp"

using coefficient = tuple<int,distance>;

class Dag {
private:
  vector< vector< coefficient > > dag;
public:
  // Make Dag of `n' nodes, no edges for now.
  Dag( int n )
    : dag( vector< vector<coefficient> >(n) ) {};
  const auto& row( int i ) const { return dag.at(i); };
  int nrows() const { return dag.size(); };
  void make_edges( int avg_degree ) {
    const int n = dag.size();
    assert( avg_degree>=0 and avg_degree<n );
    // each row gets approx `avg_degree' edges
    for ( auto& row: dag ) {
      auto degree = random_degree(avg_degree);
      assert(degree>=0 && degree<n);
      for ( int c=0; c<degree; ) {
        int neighbor = random_int(n);
        assert( neighbor>=0 && neighbor<n );
        if ( none_of
             ( row.begin(),row.end(),
               [neighbor]( coefficient iv ) {
		 auto [i,v] = iv; return i==neighbor; } )
             ) {
          row.push_back( {neighbor,chance()} );
          c++;
        }
      }
      sort(row.begin(),row.end());
    }
  };
  string as_string() const {
    stringstream ss; int irow=0;
    for (  const auto& row : dag ) {
      ss << irow++ << " => ";
      for ( auto [c,v] : row )
	ss << "(" << c << ":" << v << "), ";
      ss << '\n';
    }
    return ss.str();
  };
};

int main() {

  Dag graph(20); graph.make_edges(3);
  cout << graph.as_string();
  
  LevelSet distances(graph.nrows());
  for ( int level=1; ; level++ ) {
    // cout << "Level " << level << '\n';
    LevelSet update(distances);
    bool updates{false};
    for ( int n=0; n<update.size(); n++ ) {
      //cout << ".. node " << n;
      auto d = distances.at(n);
      if (d!=inf_distance) {
	//cout << " already known: d(" << n << ") = " << d << '\n';
	continue; }
      const auto& row = graph.row(n);
      for ( auto [j,v] : row ) {
	auto d = distances.at(j);
        if ( d!=inf_distance ) {
	  //cout << " updated to " << d+v;
	  update.at(n) = d+v; updates = true;
	}
      }
      //cout << '\n';
    }
    if (updates) {
      distances = update;
    } else
      break;
    cout << "Level " << level << ": "
         << distances.as_string() << '\n';
  }
  
  return 0;
}
