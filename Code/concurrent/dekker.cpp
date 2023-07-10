/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** dekker : example from Ori Lahav : weak memory concurrency in C++11
 ****
 ****************************************************************/


#include <iostream>
using std::cout;
#include <thread>
using std::thread;

int X,Y,a,b;
void thread1() {
  X = 1; a = Y;
};
void thread2() {
  Y = 1; b = X;
};
int main() {
  long int cnt=0;
  do {
    X = 0; Y = 0;
    thread first(thread1);
    thread second(thread2);
    first.join();
    second.join();
    ++cnt;
  } while (a!=0 || b!=0);
  cout << cnt << '\n';
  return 0;
}

