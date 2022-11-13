#include <iostream>
#include <vector>
using std::cout,std::cerr,std::endl,std::vector;
// using namespace std;

#define N 10

int main(){
  
  int index=5;              // LOCATION 1
  vector<int> memberList;
  // int index=5;              // LOCATION 2

  for (int i=0; i<N; i++) {
    cerr << "push " << i << endl;
    memberList.push_back(i);
  }
  for (auto &m : memberList)
    cerr << "here " << m <<endl;

  auto &vec = memberList;

  vec.erase
    ( std::remove(vec.begin(), vec.end(), index),
      vec.end());

  for (auto &m : memberList)
    cerr << "after " << m <<endl;

  return 0;
  
}
