#include <iostream>
using std::cout;

//codesnippet tddmain
#include "functions.h"
int main() {
  for ( int i=10; i>-1; i-- )
    cout << "One more than the positive number "
         << i << " is "
         << increment_positive_only(i)
         << '\n';
//codesnippet end
  return 0;
}
