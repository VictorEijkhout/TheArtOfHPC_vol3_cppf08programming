#include <iostream>

#include <vector>
using std::vector;

#include <variant>
using std::variant;

class particle {
private:
  float i{1};
public:
  auto value() const { return i; };
};

class maybe_partitioned_box; // forward

class box {
public:
  float com() const { return 1.; };
  auto force_on( const particle &p ) const {
    return 1+p.value();
  };
};

class partitioned_box {
private:
  vector< maybe_partitioned_box > subdivisions;
public:
  float com() const;
  float force_on( const particle &p ) const;
};

class maybe_partitioned_box {
private:
  variant< box,partitioned_box > contents{ box() };
  class take_com {
  public:
    float operator() ( const box &b ) const { return b.com(); };
    float operator() ( const partitioned_box &b ) const { return b.com(); };
  };
  class compute_force {
  private:
    particle p;
  public:
    compute_force( const particle &p ) : p(p) {};
    float operator() ( box b ) const {
      return b.force_on(p); };
    float operator() ( partitioned_box b ) const {
      return b.force_on(p); };
  };
public:
  float com() const;
  float force_on( const particle &p ) const;
};

float partitioned_box::com() const { return subdivisions.at(0).com(); };
float maybe_partitioned_box::com() const {
  return std::visit( take_com{},contents );
};

float partitioned_box::force_on( const particle &p ) const {
  float sum{0.};
  for ( const auto &s : subdivisions )
    sum += s.force_on(p);
  return sum;
};
float maybe_partitioned_box::force_on( const particle &p ) const {
  return std::visit( compute_force{p},contents );
};

int main() {

  
  return 0;
}
