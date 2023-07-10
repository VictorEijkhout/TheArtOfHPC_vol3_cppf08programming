/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** singlesource.cxx : shortest path exploration
 ****
 ****************************************************************/

#include <algorithm>
using std::max;

#include <iostream>
using std::cin, std::cout;
#include <iomanip>
using std::setw;
#include <sstream>
using std::stringstream;
#include <string>
using std::string;

#include <map>
using std::map;
#include <set>
using std::set;

#include <random>
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

class Dag {
private:
  vector< vector<int> > dag;
public:
  // Make Dag of `n' nodes, no edges for now.
  Dag( unsigned n )
    : dag( vector< vector<int> >(n) ) {};
  const auto& neighbors( size_t i ) const { return dag.at(i); };
  void make_edges( unsigned avg_degree ) {
    const auto n = dag.size();
    assert( avg_degree>=0 and avg_degree<n );
    // each row gets approx `avg_degree' edges
    for ( auto& neighbors: dag ) {
      auto degree = random_degree(avg_degree);
      assert(degree>=0 && degree<n);
      for ( int c=0; c<degree; ) {
        int neighbor = random_int(n);
        assert( neighbor>=0 && neighbor<n );
        if ( none_of
             ( neighbors.begin(),neighbors.end(),
               [neighbor](int i) { return i==neighbor; } )
             ) {
          neighbors.push_back(neighbor);
          ++c;
        }
      }
      sort(neighbors.begin(),neighbors.end());
    }
  };
  string as_string() const {
    stringstream ss; int ineighbors=0;
    for (  const auto& neighbors : dag ) {
      ss << ineighbors++ << " => ";
      for ( auto e : neighbors ) ss << setw(3) << e << ", "; ss << '\n';
    }
    return ss.str();
  };
};

int main() {

  const int graph_size = 20;
  Dag graph(graph_size); graph.make_edges(3);
  cout << graph.as_string();
  
  map<int,int> distances;
  int starting_node = 0;
  distances[starting_node] = 0;
  set<int> current_front;
  current_front.insert(starting_node);

  // while not done
  for ( int max_dist=1; ; ++max_dist ) {
    cout << "\nFront:";
    for ( auto x : current_front ) cout << " " << x;
    cout << " at max dist " << max_dist << '\n';
    set<int> next_front;
    // iterate over current_front
    for ( auto node : current_front ) {
      auto dist_to_this_node = distances[node];
      // iterate over all of their neighbors, giving them d=ell+1
      cout << "Investigate node " << node << " with dist " << dist_to_this_node << '\n';
      for ( const auto& neighbor : graph.neighbors(node) ) {
	if ( auto find_neighbor = distances.find(neighbor) ; find_neighbor==distances.end() ) {
	  cout << " .. neighbor " << neighbor 
	       << " gets distance " << dist_to_this_node+1 << '\n';
	  distances[neighbor] = dist_to_this_node+1;
	  next_front.insert(neighbor);
	} 
      }
    }
    if ( distances.size()==graph_size ) {
      cout << "Whole graph mapped\n"; break; }
    if (next_front.size()==0) {
      cout << "Graph is not simply connected\n"; break; }
    current_front = next_front;
  }

  return 0;

}

