#include <array>
using namespace std;

int main() {
  int i=1,j=1;
  array< array<int,2>,2 >{ (i,j), (i,j) };
  return 0;
}
