#include <vector>
using std::vector;

class State {
private:
  vector<bool> probabilities;
public:
  State(int size) {
    probabilities = vector<bool>(size,false);
  };
  bool &at(int i) { return probabilities.at(i); };
};
