/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2019-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** reduce.cxx : use of reductions
 ****
 ****************************************************************/


#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

//codesnippet vecaccumulate
#include <numeric>
using std::accumulate;
//codesnippet end
//codesnippet vecproduct
using std::multiplies;
//codesnippet end

//codesnippet classaccumulate1
class x {
public:
  int i,j;
  x() {};
  x(int i,int j) : i(i),j(j) {};
};
//codesnippet end

int main() {

  {
    cout << "Accumulate .." << '\n';
    //codesnippet vecaccumulate
    vector<int> v{1,3,5,7};
    auto first = v.begin();
    auto last  = v.end();
    auto sum = accumulate(first,last,0);
    cout << "sum: " << sum << '\n';
    //codesnippet end
    cout << ".. accumulate" << '\n';
  }

  {
    cout << "Product .." << '\n';
    //codesnippet vecproduct
    vector<int> v{1,3,5,7};
    auto first = v.begin();
    auto last  = v.end();
    ++first; last--;
    auto product =
      accumulate(first,last,2,
                 multiplies<>());
    cout << "product: " << product << '\n';
    //codesnippet end
    cout << ".. product" << '\n';
  }

  {
    cout << "Class .. \n";
    //codesnippet classaccumulate2
    std::vector< x > xs(5);
    auto xxx = 
      std::accumulate
      ( xs.begin(),xs.end(),0,
	[] ( int init,x x1 ) -> int { return x1.i+init; }
	);
    //codesnippet end
    cout << ".. class\n";
  }
  
  return 0;
}

