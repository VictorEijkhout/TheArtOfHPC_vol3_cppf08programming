/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2020-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** the C++ permutation generator
 ****
 ****************************************************************/

#include <iostream>
using std::cin, std::cout;
#include <vector>
using std::vector;
#include <numeric>
using std::iota;

#include <random>

int main() {

  std::random_device r;
  auto shuffle30 = std::shuffle_order_engine<std::default_random_engine,30>();

  for (int i=0; i<30; i++) {
    auto irand = shuffle30();
    cout << irand << " ";
  }
  cout << '\n';

  {
    //codesnippet vectorshuffle
    std::vector<int> idxs(20);
    iota(idxs.begin(),idxs.end(),0);
    //codesnippet end

    std::copy(idxs.begin(), idxs.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
 
    std::mt19937 g(r());
    //codesnippet vectorshuffle
    std::shuffle(idxs.begin(), idxs.end(), g);
    //codesnippet end
 
    std::copy(idxs.begin(), idxs.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
  }

  return 0;
}
