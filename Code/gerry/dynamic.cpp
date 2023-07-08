#include <iostream>
using std::cout;
#include <cmath>
using std::min;

#define DISTRICTS 100
#define MAJORITY 51
#define ELECTORS 10

int minority(int majority_to_assign,int minority_to_assign,int current_elector,int current_surplus) {
  int new_surplus;
  int majority_to_current=100,minority_to_current=100,majority_to_new=100,minority_to_new=100;

  // case: assign majority district to current elector
  if (majority_to_assign>0) {
    majority_to_current = minority(majority_to_assign-1,minority_to_assign,  current_elector,  current_surplus+1);
    if (current_elector==ELECTORS-1) {
      majority_to_new = 100;
    } else {
      // case: assign majority district to next elector
      majority_to_new   = minority(majority_to_assign-1,minority_to_assign,  current_elector+1,+1);
    }
  }
  // case: assign minority district to current elector
  if (minority_to_assign>0) {
    minority_to_current = minority(majority_to_assign,  minority_to_assign-1,current_elector,  current_surplus-1);
    if (current_elector==ELECTORS-1) {
      minority_to_new = 100;
    } else {
      // case: assign minority district to next elector
      minority_to_new   = minority(majority_to_assign  ,minority_to_assign-1,current_elector+1,-1);
    }
  }
  return min(majority_to_current,min(minority_to_current,min(majority_to_new,minority_to_new)));
}

int main() {

  int cheat = minority(MAJORITY,DISTRICTS-MAJORITY,0,0);
  cout << "Cheating minority: " << cheat << '\n';
  
  return 0;
}
