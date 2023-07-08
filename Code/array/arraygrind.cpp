/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016/7 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** arraygrind.cxx : memory violation code
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

int main() {
    int array_length;
    cout << "How many elements?";
    cin >> array_length;
    double *my_array = new double[array_length];
    
    for (int i=0; i<=array_length; i++) {
      my_array[i] = 2.1*i;
    }

    return 0;
}
