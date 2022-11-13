/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2020-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** walk.css :  random walks
 ****
 ****************************************************************/

#include "walk_lib_pass.cxx"

#include <chrono>
using namespace std::chrono;

int main() {

  const int experiments = 5;
  for ( auto dim : {3} ) {
    for ( auto cache : {false,true} ) {
      auto start_time = high_resolution_clock::now();
      for ( auto steps : { 10000,100000,1000000 } ) {
        float avg_dist{0.f};
        for ( int x=0; x<experiments; x++ ) {
          Mosquito m(dim,cache);
          for (int step=0; step<steps; step++)
            m.step();
          avg_dist += m.distance();
        }
        avg_dist /= experiments;
        cout << "D=" << dim
             << " after " << steps
             << " steps, distance= " << avg_dist
          //<< " dist/sqrt(steps): " << avg_dist/sqrt(steps)
             << '\n';
      }
      auto end_time = high_resolution_clock::now();
      auto duration = duration_cast<milliseconds>(end_time - start_time).count();
      cout << "run took: " << duration << " milliseconds" << '\n';
    }
  }
  return 0;
}
