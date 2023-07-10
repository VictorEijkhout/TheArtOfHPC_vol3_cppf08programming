/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2022-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** customit.cxx : example of class with iterator
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class NewVector {
private:
  int *storage;
  int s;
public:
  NewVector( int s )
    : s(s){
    storage = new int[s]; };
  ~NewVector() { delete storage; };
  int at(int i) const { if (i<0 or i>=s) throw;
    return storage[i]; };
  int& at(int i) { if (i<0 or i>=s) throw;
    return storage[i]; };
  class iter {
  private: int *searcher;
  public:
    iter( int *searcher ) : searcher(searcher) {};
    iter& operator++() { ++searcher; return *this; };
    iter& operator--() { searcher--; return *this; };
    int& operator*() { return *searcher; };
    bool operator==( const iter &other ) const { return searcher==other.searcher; };
    bool operator!=( const iter &other ) const { return searcher!=other.searcher; };
  };
  iter begin() { return iter(storage); };
  iter end()   { return iter(storage+s); };
};

int main() {

  const int s = 5;
  NewVector v(s);
  for ( int i=0; i<s; ++i )
    v.at(i) = i+1;

  for ( auto e : v )
    cout << e << " ";
  cout << '\n';

  return 0;
}
