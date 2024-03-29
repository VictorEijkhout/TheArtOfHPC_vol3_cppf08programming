/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2020-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** walk.css :  random walks, naive implementation
 ****
 ****************************************************************/

#include "walk_lib_vec.cpp"

#include <chrono>
using namespace std::chrono;

int main() {

  const int experiments = 5;
  for ( auto dim : {3} ) {
    auto start_time = high_resolution_clock::now();
    for ( auto steps : { 10000,100000,1000000 } ) {
      //codesnippet walkrun
      float avg_dist{0.f};
      for ( int x=0; x<experiments; ++x ) {
        Mosquito m(dim);
        for (int step=0; step<steps; ++step)
          m.step();
        avg_dist += m.distance();
      }
      avg_dist /= experiments;
      //codesnippet end
      cout << "D=" << dim
           << " after " << steps
           << " steps, distance= " << avg_dist
        //           << " dist/sqrt(steps): " << avg_dist/sqrt(steps)
           << '\n';
    }
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end_time - start_time).count();
    cout << "run took: " << duration << " milliseconds" << '\n';
  }
  return 0;
}
