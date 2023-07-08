#include <iostream>
using namespace std;

enum class bits : int { one=1, two=2 };

int operator |( const bits& x,const bits& y ) {
  return static_cast<int>(x) | static_cast<int>(y);
};

int main() {
  cout << ( bits::one | bits::two ) << '\n';

  return 0;
}
