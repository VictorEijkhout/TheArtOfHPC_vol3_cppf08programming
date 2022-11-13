/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** printeach.cxx : use of for_each
 ****
 ****************************************************************/


#include <iostream>
using std::cin;
using std::cout;

//codesnippet printeach
#include <algorithm>
using std::for_each;
//codesnippet end

#include <vector>
using std::vector;

int main() {

  cout << "Print" << '\n';
  //codesnippet printeach
  vector<int> ints{3,4,5,6,7};
  for_each
    ( ints.begin(),ints.end(),
      [] (int x) -> void {
	if (x%2==0)
	  cout << x << '\n';
      } );
  //codesnippet end
  cout << "print" << '\n';

  cout << "Count" << '\n';
  //codesnippet counteach
  vector<int> moreints{8,9,10,11,12};
  int count{0};
  for_each
    ( moreints.begin(),moreints.end(),
      [&count] (int x) {
	if (x%2==0)
	  count++;
      } );
  cout << "number of even: " << count << '\n';
  //codesnippet end
  cout << "count" << '\n';

  return 0;
}

