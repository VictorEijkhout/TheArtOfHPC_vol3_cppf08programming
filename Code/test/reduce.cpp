#include <vector>
#include <numeric>

class x {
public:
  int i,j;
  x() {};
  x(int i,int j) : i(i),j(j) {};
};
int main() {
  std::vector< x > xs(5);
  auto xxx = 
    std::accumulate
    ( xs.begin(),xs.end(),0,
      [] ( int init,x x1 ) -> int { return x1.i+init; }
      );
  return 0;
}

#if 0
std::vector<int> is(5);
  auto iii = std::accumulate
    ( is.begin(),is.end(),
      0,
      [] (int i,int j) { return i+j; }
      );
#endif
