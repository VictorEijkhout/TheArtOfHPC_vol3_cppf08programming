/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** itera.cxx : use of iterators
 ****
 ****************************************************************/


#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int main() {

  {
    cout << "Iter" << '\n';
    //codesnippet veciterator
    vector<int> v{1,3,5,7};
    auto pointer = v.begin();
    cout << "we start at "
	 << *pointer << '\n';
    ++pointer;
    cout << "after increment: "
	 << *pointer << '\n';

    pointer = v.end();
    cout << "end is not a valid element: "
	 << *pointer << '\n';
    pointer--;
    cout << "last element: "
	 << *pointer << '\n';
    //codesnippet end
    cout << "iter" << '\n';
  }

  {
    cout << "Erase.." << '\n';
    //codesnippet vecerase
    vector<int> v{1,3,5,7,9};
    cout << "Vector: ";
    for ( auto e : v ) cout << e << " ";
    cout << '\n';
    auto first = v.begin();
    ++first;
    auto last = v.end();
    last--;
    v.erase(first,last);
    cout << "Erased: ";
    for ( auto e : v ) cout << e << " ";
    cout << '\n';
    //codesnippet end
    cout << "..erase" << '\n';
  }

  return 0;
}

