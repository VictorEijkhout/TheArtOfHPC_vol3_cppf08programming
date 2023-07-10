/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2020-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** the C++ permutation generator
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;
#include <iomanip>
using std::setw;

#include <vector>
using std::vector;
#include <numeric>
using std::iota;

#include <random>
#include <algorithm>
using std::for_each;


int main() {

  std::random_device r;
  /*
   * I'm not sure what this does
  auto shuffle30 = std::shuffle_order_engine<std::default_random_engine,30>();

  for (int i=0; i<30; ++i) {
    auto irand = shuffle30();
    cout << irand << " ";
  }
  cout << '\n';
  */
  
  auto by_10s =
    [count=0] (auto val) mutable {
      if (count>0 and count%10==0) { cout << '\n'; }
      cout << setw(3) << val << " "; ++count;
    };

  {
    //codesnippet vectorshuffle
    std::vector<int> idxs(20);
    iota(idxs.begin(),idxs.end(),0);
    //codesnippet end

    cout << "Iota:\n";
    for_each( idxs.begin(), idxs.end(), by_10s );
    cout << '\n';
 
    std::mt19937 g(r());
    //codesnippet vectorshuffle
    std::shuffle(idxs.begin(), idxs.end(), g);
    //codesnippet end
 
    cout << "Permute:\n";
    for_each( idxs.begin(), idxs.end(), by_10s );
    cout << '\n';
 
  }

  return 0;
}
