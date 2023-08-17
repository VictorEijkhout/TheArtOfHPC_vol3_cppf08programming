/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** subspan.cxx : using c++20 span
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <vector>
using std::vector;
//codesnippet subspan
#include <span>
using std:: span;
//codesnippet end

int main() {

  {
    cout << "SPAN1\n";
    //codesnippet subspan1
    vector v{1,2,3};
    span tail( v.data()+1,2 );
    tail[0] = 0;
    cout << v[0] << ','
         << v[1] << ','
         << v[2] << '\n';
    //codesnippet end
    cout << "span1\n";
  }
  {
    cout << "SPAN2\n";
    //codesnippet subspan2
    vector v{1,2,3};
    span data( v.data(),v.size() );
    span tail = data.last(2);
    for ( auto& e : tail )
      e = 0;
    cout << v[0] << ','
         << v[1] << ','
         << v[2] << '\n';
    //codesnippet end
    cout << "span2\n";
  }

  return 0;
}
