/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** arraycopy.cxx : example program for performace measurement
 ****
 ****************************************************************/

#include <chrono>

#include <iostream>
using std::cout;
#include <vector>
using std::vector;

#include <random>
using std::default_random_engine,std::random_device,std::mt19937,
  std::uniform_real_distribution,std::uniform_int_distribution;

float get_random_elt( vector<float> &data ) {
  static random_device rd;
  static std::default_random_engine random_generator{ rd() };
  uniform_int_distribution<int> int_dist(0,data.size()-1);
  auto index = int_dist(random_generator);
  return data.at(index);
};

int main() {
  vector<float> data(1000000,2.f);

  std::chrono::system_clock::time_point point;
  point = std::chrono::system_clock::now();

  float s = 0;
  for ( int i=0; i<10000; i++ )
    s += get_random_elt( data );

  auto duration = std::chrono::system_clock::now()-point;
  auto millisec_duration = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
  cout << "Compute " << s << " in time: " << millisec_duration.count()*1.e-3 << '\n';

  return 0;
};
