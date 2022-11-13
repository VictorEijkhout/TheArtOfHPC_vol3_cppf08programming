/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** arraytime.cxx : time the overhead for flexible vectors
 ****
 ****************************************************************/

#include <chrono>
//using std::chrono::system_clock::time_point;

#include <iostream>
using std::cin, std::cout;

#include <vector>
using std::vector;

#define LENGTH 100000000

int main() {

  std::chrono::system_clock::time_point point;
  double check = 0.;

  {
    //codesnippet vectorflex
    vector<int> flex;
    //codesnippet end
    point = std::chrono::system_clock::now();
    //codesnippet vectorflex
    for (int i=0; i<LENGTH; i++)
      flex.push_back(i);
    //codesnippet end
    auto duration = std::chrono::system_clock::now()-point;
    auto millisec_duration = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    cout << "Flexible time: " << millisec_duration.count()*1.e-3 << '\n';
    check += flex.size();
  }
  
  {
    //codesnippet vectorat
    vector<int> stat(LENGTH);
    //codesnippet end
    point = std::chrono::system_clock::now();
    //codesnippet vectorat
    for (int i=0; i<LENGTH; i++)
      stat.at(i) = i;
    //codesnippet end
    auto duration = std::chrono::system_clock::now()-point;
    auto millisec_duration = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    cout << "Static at time: " << millisec_duration.count()*1.e-3 << '\n';
    check += stat.size();
  }
  
  {
    //codesnippet vectorsub
    vector<int> stat(LENGTH);
    //codesnippet end
    stat[0] = 0.;
    point = std::chrono::system_clock::now();
    //codesnippet vectorsub
    for (int i=0; i<LENGTH; i++)
      stat[i] = i;
    //codesnippet end
    auto duration = std::chrono::system_clock::now()-point;
    auto millisec_duration = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    cout << "Static assign time: " << millisec_duration.count()*1.e-3 << '\n';
    check += stat.size();
  }
  
  {
    //codesnippet vectornew
    int *stat = new int[LENGTH];
    //codesnippet end    
    point = std::chrono::system_clock::now();
    //codesnippet vectornew
    for (int i=0; i<LENGTH; i++)
      stat[i] = i;
    //codesnippet end    
    auto duration = std::chrono::system_clock::now()-point;
    auto millisec_duration = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    cout << "Static assign time to new: " << millisec_duration.count()*1.e-3 << '\n';
    check += stat[LENGTH-1]+1;
  }
  cout << "check sum " << check << '\n';

  return 0;
}
