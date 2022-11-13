/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** starconst.cxx : illustrating star with C pointers
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

void change1( int *p ) {
  *p = 5;
};
void change2( int *p ) {
  p++;
};
void change3( int *p ) {
  free(p);
};
void change4( int ** p ) {
  free(*p);
};

int main() {

  {
    cout << "CPTRINC" << '\n';
    //codesnippet cptrinc
    int value = 5;
    int *ptr = &value;
    *ptr += 1;
    cout << "value: " << value << '\n';
    cout << "*ptr: " << *ptr << '\n';
    ptr += 1;
    cout << "random memory: " << *ptr << '\n';
    //codesnippet end
    cout << "cptrinc" << '\n';
  }

  {
    //codesnippet cptrconst
    int value = 5;
    int *const ptr = &value;
    *ptr += 1;
    /* DOES NOT COMPILE: cannot assign to variable 'ptr' with const-qualified type 'int *const'
    ptr += 1;
    */
    //codesnippet end
  }

  {
    //codesnippet cptrtoconst
    const int value = 5; // value is const
    /* DOES NOT COMPILE: cannot convert const int* to int*
    int *ptr = &value;
    */
    //codesnippet end
  }

  {
    int *ptr = (int*) malloc(sizeof(int));
    *ptr = 2;
    cout << "starting *ptr: " << (long)ptr << "=" << *ptr << '\n';
    free(ptr);
    cout << "freed    *ptr: " << (long)ptr << "=" << *ptr << '\n';
    
  }
  {
    int *ptr = (int*) malloc(sizeof(int));
    *ptr = 2;
    cout << "starting *ptr: " << (long)ptr << "=" << *ptr << '\n';
    change1(ptr);
    cout << "change1: *ptr: " << (long)ptr << "=" << *ptr << '\n';
    change2(ptr);
    cout << "change2: *ptr: " << (long)ptr << "=" << *ptr << '\n';
    change3(ptr);
    cout << "change3: *ptr: " << (long)ptr << "=" << *ptr << '\n';
    // change4(&ptr);
    // cout << "change4: *ptr: " << (long)ptr << "=" << *ptr << '\n';
  }

  return 0;
}
