/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** cxx : example
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

int main() {

    int left=0, right=0;
    while (true) {
	if ( int dist = right-left ; dist<100 ) {
	    left--; ++right;
	} else break;
    }

    return 0;
}
