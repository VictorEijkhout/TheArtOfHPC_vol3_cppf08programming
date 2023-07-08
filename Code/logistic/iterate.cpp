#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

using scalar = double;
using cycle = vector<scalar>;

class sequence {
private:
  scalar r;
  scalar cur;
public:
  sequence(scalar r) 
    : r(r) {cur = .5;};
  auto iterate(scalar in,int steps=1) {
    scalar result{in};
    for (int step=0; step<steps; step++)
      result = r * result * (1-result); 
    return result;
  };
  auto current() const { return cur; };
  auto next() {
    cur = iterate(cur);
    return cur;
  };
  auto detect_fixed_cycle(int dist=1) {
    auto wiggle = 1.;
    while (wiggle>1.e-5 and current()>1.e-50) {
      auto point = current();
      auto new_point = next();
      wiggle = abs(point-new_point)/abs(point);
    };
    if (current()<1.e-50)
      return cycle{0.*current()};
    else
      return cycle{current()};
  };
};

int main() {

    scalar r;
    cout << "r?" << '\n';
    cin >> r;

    {
      sequence seq(r);
      scalar value=.5;
      for ( int step=0; step<5; step++ ) {
        value = seq.iterate(value);
        cout << value << '\n';
      }
    }

    for ( scalar r=.1 ; r< 1.5; r+=.1 ) {
      sequence seq(r);
      cout << "with r=" << r << ":" << '\n';
      auto fixed = seq.detect_fixed_cycle();
      cout << "  found fixed point: " << fixed.at(0) << '\n';
    }

    return 0;
}
