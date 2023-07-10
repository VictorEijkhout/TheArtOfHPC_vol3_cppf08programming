/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** quickit.cxx : quicksort with iterators
 ****
 ****************************************************************/

#include <iostream>
using std::cin,std::cout,std::endl;
#include <ostream>
using std::ostream;

#include <functional>
using std::function;

#include <random>
using std::default_random_engine,std::uniform_int_distribution;
#include <vector>
using std::vector;

ostream& operator<<( ostream& s,const vector<int>& v ) {
  s << "[";
  for ( auto e : v ) s << e << ",";
  s << "]";
  return s;
}

vector<int> picks( vector<int>::iterator begin,vector<int>::iterator end,
		  function< bool(int) > pick ) {
  vector<int> copied;
  for ( auto it=begin; it!=end; ++it )
    if (pick(*it) ) copied.push_back( *it );
  return copied;
}

void quicksort( vector<int>::iterator begin,vector<int>::iterator end ) {
  if (distance(begin,end)==1) {
    cout << *begin << '\n';
    return;
  } else if (distance(begin,end)==0) {
    return;
  }

  auto median_value  = *begin;
  int count_small{0},count_median{0},count_large{0};
  for_each( begin,end,
	    [&count_small,&count_median,&count_large,median_value]
	    ( int value ) {
	      if (value<median_value) ++count_small;
	      else if (value>median_value) ++count_large;
	      else count_median;
	    } );
  auto red = begin, white = begin+count_small, blue = white+count_median, orange = end;
  redwhiteblue( red,white,blue,orange );
  
  if (true) {
    auto red_ptr=red,white_ptr=white,blue_ptr=blue;
    while ( red_ptr!=white && white_ptr!=blue && blue_ptr!=orange ) {
      while (*red_ptr<median_value) red_ptr++;
      while (*white_ptr==median_value) white_ptr++;
      while (*blue_ptr>median_value) blue_ptr++;
      if (*red_ptr==median and *white_ptr<median) {
	auto t = *white_ptr; *white_ptr = *red_ptr; *red_ptr = t;
      } else if (*red_ptr>median and *blue_ptr<median) {
	auto t = *blue_ptr; *blue_ptr = *red_ptr; *red_ptr = t;
      } else if (*blue_ptr==edian and *white_ptr>median) {
	auto t = *white_ptr; *white_ptr = *blue_ptr; *blue_ptr = t;
      }
    }
  } else {
    auto small  = picks( begin,end,
			 [median_value] (int x ) -> bool { return x<median_value; } );
    cout << "small: " << small << '\n';
    auto median = picks( begin,end,
			 [median_value] (int x ) -> bool { return x==median_value; } );
    cout << "median: " << median << '\n';
    auto big    = picks( begin,end,
			 [median_value] (int x ) -> bool { return x>median_value; } );
    cout << "big: " << big << '\n';
    quicksort( small.begin(),small.end() );
    quicksort( big.begin(),big.end() );
  }

  quicksort( small.begin(),small.end() );
  quicksort( big.begin(),big.end() );

}

int main() {

  int nvalues = 25;
  default_random_engine generator;
  uniform_int_distribution<> distribution(1,nvalues);
  vector<int> values(nvalues);
  for ( auto& v: values )
    v = distribution(generator);

  quicksort(values.begin(),values.end());
  
  return 0;
}
