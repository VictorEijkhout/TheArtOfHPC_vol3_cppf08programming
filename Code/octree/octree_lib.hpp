/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** octree_lib.h : N-body library headers
 ****
 ****************************************************************/

#include <memory>
using std::shared_ptr;

#include <optional>
using std::optional;

#include <string>
using std::string;

#include <sstream>
using std::stringstream;

#include <variant>
using std::variant;
using std::get_if;

#include <vector>
using std::vector;

class particle {
private:
  vector<double> coordinates;
  double _weight;
public:
  particle( vector<double> coord,double weight)
    : coordinates( coord ),_weight(weight) {};
  int dimensionality() const { return coordinates.size(); };
  auto weight() const { return _weight; };
  const auto operator[](int id) const { return coordinates.at(id); };
  double distance( const particle &other ) const;
  double force_on( const particle &p ) const;
  particle operator+( const particle& other ) const;
  particle operator*( double s ) const;
  particle operator/( double s ) const;
  string as_string() const;
};

particle zero_particle(int d );

class box {
private:
  int _dimensionality{0};
  vector<particle> _particles;
  mutable optional<particle> com = {};
  double bb_size{1.};
public:
  box( int d ) : _dimensionality(d) {};
  void add( particle p );
  int dimensionality() const { return _dimensionality; };
  const auto &particles() const { return _particles; };
  particle center_of_mass() const;
  void set_bounding_box_size(double s) { bb_size = s; };
  double bounding_box_size() const { return bb_size; };
  double force_on( const particle &p /* ,double break_ratio=-1. */ ) const;
  string as_string() const;
};

/* forward definition: */ class partitioned_box;
class maybe_partitioned_box;
class partitioned_box {
private:
  vector< maybe_partitioned_box > subdivisions;
  mutable optional<particle> com = {};
  double bb_size{1.};
public:
  partitioned_box() {};
  partitioned_box( const box &bigbox );
  void add( const box &b );
  int dimensionality() const;
  particle center_of_mass() const;
  double force_on( const particle &p ) const;
  string as_string() const;
};

class maybe_partitioned_box {
private:
  //  variant<box,shared_ptr<partitioned_box>> contents{ box(1) };
  variant<box,partitioned_box> contents{ box(1) };
  class compute_comm {
  public:
    particle operator() ( box b )             { return b.center_of_mass(); };
    particle operator() ( partitioned_box b ) { return b.center_of_mass(); };
  };
  class compute_force_on {
  private:
    particle p;
  public:
    compute_force_on( const particle &p ) : p(p) {};
    double operator() ( const box &b ) {
      return b.force_on(p); };
    //double operator() ( const shared_ptr<partitioned_box> &b,const particle &p ) {
    double operator() ( const partitioned_box &b ) {
      return b.force_on(p); };
  };
public:
  maybe_partitioned_box( box b ) {
    contents = b; };
  //maybe_partitioned_box( shared_ptr<partitioned_box> b ) {
  maybe_partitioned_box( partitioned_box b ) {
    contents = b; };
  int dimensionality() const;
  double force_on( const particle &p /* ,double break_ratio=-1. */ ) const;
  particle center_of_mass() const;
  string as_string() const;
};
