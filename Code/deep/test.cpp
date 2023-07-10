#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

class data_vector {
private:
  vector<float> coefficients;
public:
  data_vector() : coefficients( vector<float>(5,1.) ) {};
  void trace() { cout << coefficients[0] << '\n'; };

private:
  int seek{0};
public:
  data_vector &begin() { seek = 0; return *this; };
  data_vector &end()   { seek = coefficients.size(); return *this; };
  bool operator!=( const data_vector &test ) const {
    return seek!=test.seek; };
  void operator++() { ++seek; };
  float &operator*() { return coefficients.at(seek); };
};

int main() {

  data_vector
    outdata;
  outdata.trace();
  for ( float &d : outdata )
    d = 2. ;
  outdata.trace();

  return 0;
}
