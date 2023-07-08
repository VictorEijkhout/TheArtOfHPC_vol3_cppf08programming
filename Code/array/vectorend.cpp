/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** vectorend.cxx : example of vector end iterator
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int main() {

  cout << "End Bracket" << '\n';
  {
    //codesnippet vectorpush
    vector<int> mydata(5,2);
    mydata.push_back(35);
    cout << mydata.size()
         << '\n';
    cout << mydata.back()
         << '\n';
    //codesnippet end
  }
  cout << "... bracket" << '\n';

  cout << "End Iterator" << '\n';
  {
    //codesnippet vectorpushiterator
    vector<int> mydata(5,2);
    mydata.push_back(35);
    cout << mydata.size() << '\n';
    cout << *( --mydata.end() ) << '\n';
    //codesnippet end
  }
  cout << "... iterator" << '\n';

  return 0;
}
