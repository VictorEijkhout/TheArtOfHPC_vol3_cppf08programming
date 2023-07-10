/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 ****************************************************************/

#include <iomanip>
using std::setw;

class NodeSet {
private:
  vector<int> nodes;
public:
  NodeSet() {};
  NodeSet( vector<int> n ) : nodes(n) {};
  auto size() const { return nodes.size(); };
  bool has(int i) const {
    return any_of
      ( nodes.begin(),nodes.end(),[i] (auto n ) { return i==n; } );
  };
  void add(int i) {
    nodes.push_back(i);
  };
  void add( NodeSet ins ) {
    nodes.insert( nodes.end(),ins.nodes.begin(),ins.nodes.end() );
  };
  /* Iterating */
private:
  int seek{0};
public:
  NodeSet begin() const { auto b = *this; b.seek=0; return b; };
  NodeSet end()   const { auto b = *this; b.seek=nodes.size(); return b; };
  bool operator!=( const NodeSet& other ) const {
    return seek!=other.seek; };
  void operator++() { ++seek; };
  distance operator*() const { return nodes.at(seek); };
};

class LevelSet {
private:
  vector<distance> distances;
public:
  LevelSet( int size )
    : distances( vector<distance>(size,inf_distance) ) {};
  int size() const { return distances.size(); };
  auto& at(int i) { return distances.at(i); };
  auto at(int i) const { return distances.at(i); };
  bool has(int n) const { return distances.at(n)!=inf_distance; };
  void set_distance(int n,int d) { distances.at(n) = d; };
  void add( NodeSet nodes,int d ) {
    for ( auto n : nodes )
      set_distance(n,d);
  };
  /*
   * Iterating over object
   */
private:
  int seek{0};
public:
  LevelSet begin() const { auto b = *this; b.seek=0; return b; };
  LevelSet end()   const { auto b = *this; b.seek=distances.size(); return b; };
  bool operator!=( const LevelSet& other ) const {
    return seek!=other.seek; };
  void operator++() { ++seek; };
  distance operator*() const { return distances.at(seek); };
  /* 
   * Utility stuff
   */
  string as_string() const {
    stringstream ss;
      for ( auto n : distances )
	ss << " " << setw(3) << n;
      return ss.str();
  };
};

