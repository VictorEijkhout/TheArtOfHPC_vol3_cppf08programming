/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** iter.cxx : tinkering with iterators
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <iomanip>
using std::boolalpha;

#include <vector>
using std::vector;

//codesnippet algeach
#include <algorithm>
//codesnippet end

int main() {

  {
    cout << "EACH\n";
    //codesnippet algeach
    vector<int> ints{2,3,4,5,7,8,13,14,15};
    for_each( ints.begin(),ints.end(),
	      [] ( int i ) -> void {
		cout << i << '\n';
	      }
	      );
    //codesnippet end
    cout << "each\n";
  }
  {
    cout << "ANY\n";
    //codesnippet algany
    vector<int> ints{2,3,4,5,7,8,13,14,15};
    bool there_was_an_8 = 
      any_of( ints.begin(),ints.end(),
	      [] ( int i ) -> bool {
		return i==8;  
	      }
	      );
    cout << "There was an 8: " << boolalpha << there_was_an_8 << '\n';
    //codesnippet end
    cout << "any\n";
  }
  {
    cout << "SUMMING\n";
    //codesnippet algsumming
    vector<int> ints{2,3,4,5,7,8,13,14,15};
    int sum=0;
    for_each( ints.begin(),ints.end(),
	      [&sum] ( int i ) -> void {
		sum += i;
	      }
	      );
    cout << "Sum = " << sum << '\n';
    //codesnippet end
    cout << "summing\n";
  }

  return 0;
}
