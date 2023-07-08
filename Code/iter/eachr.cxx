/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** iter.cxx : tinkering with ranges
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <iomanip>
using std::boolalpha;

#include <vector>
using std::vector;

//codesnippet algeachr
#include <ranges>
#include <algorithm>
//codesnippet end

int main() {

  {
    cout << "EACH\n";
    //codesnippet algeachr
    vector<int> ints{1,2,3,4,5,7,8,13,14};
    std::ranges::for_each
      ( ints,
        [] ( int i ) -> void {
          cout << i << '\n';
        }
        );
    //codesnippet end
    cout << "each\n";
  }
  {
    cout << "CAPTURE\n";
    //codesnippet alganyrc
    vector<int> ints{1,2,3,4,5,7,8,13,14};
    int tofind = 8;
    bool there_was_an_8 = 
      std::ranges::any_of
      ( ints,
        [tofind] ( int i ) -> bool {
          return i==tofind;  
        }
        );
    cout << "There was an 8: " << boolalpha << there_was_an_8 << '\n';
    //codesnippet end
    cout << "capture\n";
  }
  {
    cout << "ANY\n";
    //codesnippet alganyr
    vector<int> ints{1,2,3,4,5,7,8,13,14};
    bool there_was_an_8 = 
      std::ranges::any_of
      ( ints,
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
    //codesnippet algsummingr
    vector<int> ints{1,2,3,4,5,7,8,13,14};
    int sum=0;
    std::ranges::for_each
      ( ints,
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
