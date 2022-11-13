/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** staticinit.cxx : initialization of static arrays
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <vector>
using std::vector;

int main() {

  /*
   * first element gets set, 
   * everything else zero
   */
  //codesnippet carrayinitconst1
  {
    int numbers[2] = {2};
    cout << numbers[0] << "," << numbers[1] << '\n';
  }
  //codesnippet end
  
  /*
   * first element gets set, 
   * everything else zero
   */
  //codesnippet carrayinitconst2
  {
    int numbers[2][2] = {2};
    cout << numbers[0][0] << "," << numbers[1][1] << '\n';
  }
  //codesnippet end
  
  /*
   * of course you can set the whole thing
   */
  //codesnippet carrayinitconst3
  {
    int numbers[2][2] = {{1,2},{3,4}};
    cout << numbers[0][0] << "," << numbers[1][1] << '\n';
  }
  //codesnippet end
  
  // vector<int> f(4,5);
  // int *x[] = (int(*)[2]) f.data();

  return 0;
}
