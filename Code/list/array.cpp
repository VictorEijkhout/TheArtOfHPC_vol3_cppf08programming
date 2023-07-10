/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** array.cxx : measure speed of array access
 ****
 ****************************************************************/

#include <chrono>
#include <cstring> // for memcpy

#include <iostream>
using std::cin;
using std::cout;

int main() {

#define NEXPERIMENTS 10

  std::chrono::system_clock::time_point point;

  /*
   * We expand an array by reallocating.
   * We do this for various maximum sizes,
   * and at each size multiple experiments.
   */
  cout << "Reallocation" << '\n';
  for (size_t size=10; size<100000000; size*=10) {
    cout << "Maximum size: " << size << '\n';
    point = std::chrono::system_clock::now();

    double *a1;
    double total=0.;
    for (int x=0; x<NEXPERIMENTS; ++x) {

      /*
       * Extend an array by repeatedly copying to a larger one
       */

      // set initial size and increment
      size_t siz=size-2, inc=2;

      // allocate starting array
      a1 = new double[siz];

      // increase the siz, reallocating the array
      for ( ; siz<size; ) {
	
	// allocate a2, slightly bigger than a1
	double *a2 = new double[siz+inc];
	
	// copy a1 to a2
	for (size_t i=0; i<siz+inc; ++i)
	  a2[i] = a1[i];
	// extend a2
	for (size_t i=siz; i<siz+inc; ++i) {
	  a2[i] = (double)siz;
	  total += a2[i];
	}
	
	// reallocate a1 and copy a2 over
	delete a1;
	siz += inc;
	a1 = new double[siz];
	memcpy(a1,a2,siz*sizeof(double));
	delete[] a2;
      }
      delete a1;
    } // end of the experiments

    auto duration = std::chrono::system_clock::now()-point;
    auto millisec_duration = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
    cout << "time: " << millisec_duration.count()*1.e-3 << '\n';
  }

  /*
   * Now do basically the same thing with a linked list
   */
  {
    class Node {
    private:
      int data;
      Node *next;
    public:
      Node(int i) {
	data = i; next = nullptr; };
      bool hastail() { return next!=nullptr; };
      Node *tail() { return next; };
      void settail( Node *n) { next = n; };
    };
    class List {
    private:
      Node *head;
    public:
      List() { head = new Node(0); };
      void zap() { head = new Node(0); };
      void append( Node *n ) {
	Node *cur = head;
	while (cur->hastail())
	  cur = cur->tail();
	cur->settail(n);
      };
    };
    
    cout << "Linked list" << '\n';
    for (size_t size=10; size<1000000; size*=10) {
      List list;

      cout << "Maximum size: " << size << '\n';
      point = std::chrono::system_clock::now();
      for (int x=0; x<NEXPERIMENTS; ++x) {

	/*
	 * Extend a list by appending at the end
	 */

	list.zap();
	for (int n=0; n<size; ++n) {
	  list.append( new Node(n) );
	}
      }
      auto duration = std::chrono::system_clock::now()-point;
      auto millisec_duration = std::chrono::duration_cast<std::chrono::milliseconds>(duration);
      cout << "time: " << millisec_duration.count()*1.e-3 << '\n';
    }
  }

  return 0;
}

