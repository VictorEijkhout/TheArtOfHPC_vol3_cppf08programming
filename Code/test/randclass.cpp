#include <iostream>
#include <random>
using namespace std;

class all {
public:
  float random_fraction() const {
    static mt19937 random_generator;
    uniform_real_distribution<float> fraction_dist(0.f,1.f);
    return fraction_dist(random_generator);
  };
  void print() const {
    cout << random_fraction() << '\n';
    cout << random_fraction() << '\n';
  };
};

int main() {
  all a;
  a.print();
  return 0;
}
