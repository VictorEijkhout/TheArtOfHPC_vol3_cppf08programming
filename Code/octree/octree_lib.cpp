/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2020-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** octree_lib.cxx : N-body library
 ****
 ****************************************************************/

#include "octree_lib.hpp"

#include <iostream>
using std::cin;
using std::cout;

#include <variant>
using std::get;
using std::visit;

#include <cmath>

double particle::distance( const particle &other ) const {
  if (dimensionality()!=other.dimensionality())
    throw(string("Particles of different dimension"));
  double squared{0.0};
  for ( int id=0; id<dimensionality(); id++) {
    auto d = coordinates[id]-other.coordinates[id];
    squared += d*d;
  }
  return sqrt(squared);
};

particle particle::operator+( const particle& other ) const {
  if (dimensionality()!=other.dimensionality())
    throw(string("Particles of different dimension"));
  vector<double> sum_coord( dimensionality() );
  auto w1 = weight(), w2 = other.weight();
  for ( int id=0; id<dimensionality(); id++)
    sum_coord.at(id) = coordinates.at(id) + other.coordinates.at(id);
  return particle( sum_coord,w1+w2 );
};

particle particle::operator*( double s ) const {
  vector<double> scaled_coord( dimensionality() );
  for ( int id=0; id<dimensionality(); id++ )
    scaled_coord.at(id) = coordinates.at(id) * s;
  return particle( scaled_coord,weight() );
};

particle particle::operator/( double s ) const {
  return *this * (1./s);
};

particle zero_particle(int d ) {
  return particle( vector<double>(d,0.), 0. );
};

void box::add( particle p ) {
  if (p.dimensionality()!=dimensionality()) {
    cout << "Can not add particle of dimensionality " << p.dimensionality()
	 << " to box of dimensionality " << dimensionality() << '\n';
    throw(1);
  }
  _particles.push_back(p); com = {};
};

partitioned_box::partitioned_box( const box &bigbox ) {
  int d = bigbox.dimensionality();
  auto center = bigbox.center_of_mass();
  if (d==1) {
    box leftbox(d),rightbox(d);
    leftbox.set_bounding_box_size( bb_size/2 );
    rightbox.set_bounding_box_size( bb_size/2 );
    for ( auto &p : bigbox.particles() ) {
      if (p[0]<center[0])
	leftbox.add(p);
      else
	rightbox.add(p);
    }
    subdivisions.push_back( leftbox ); subdivisions.push_back( rightbox ); 
  } else if (d==2) {
    box leftdownbox(d),leftupbox(d),rightdownbox(d),rightupbox(d);
    leftdownbox.set_bounding_box_size( bb_size/2 );
    leftupbox.set_bounding_box_size( bb_size/2 );
    rightdownbox.set_bounding_box_size( bb_size/2 );
    rightupbox.set_bounding_box_size( bb_size/2 );
    for ( auto &p : bigbox.particles() ) {
      if (p[0]<center[0]) {
	if (p[1]<center[1])
	  leftdownbox.add(p);
	else
	  leftupbox.add(p);
      } else {
	if (p[1]<center[1])
	  rightdownbox.add(p);
	else
	  rightupbox.add(p);
      }
    }
    subdivisions.push_back( leftdownbox );
    subdivisions.push_back( leftupbox );
    subdivisions.push_back( rightdownbox );
    subdivisions.push_back( rightupbox );
  } else { cout << "Can not split yet in d=" << d << '\n'; throw(1);
  }
};

int partitioned_box::dimensionality() const {
  const auto &div0 = subdivisions.at(0);
  return div0.dimensionality();
};

int maybe_partitioned_box::dimensionality() const {
  switch (contents.index()) {
  case 0 : return get<box>( contents ).dimensionality();
    //case 1 : return get< shared_ptr<partitioned_box> >( contents )->dimensionality();
  case 1 : return get< partitioned_box >( contents ).dimensionality();
  default : return -1;
  }
};

particle box::center_of_mass() const {
  if (!com.has_value()) {
    if (_particles.size()==0) {
      com = zero_particle( dimensionality() );
      //cout << "Can not compute center of empty box" << '\n'; throw(1);
    } else {
      particle sum_particle = zero_particle( dimensionality() );
      double sum_weight{0.};
      for ( auto &p : _particles ) {
	auto w = p.weight();
	sum_weight += w;
	sum_particle = sum_particle + p * w;
      }
      com = sum_particle/sum_weight;
    }
  }
  return com.value();
};

particle partitioned_box::center_of_mass() const {
  if (subdivisions.size()==0) {
    cout << "Can not compute center of empty partitioned box" << '\n';
    throw(1);
  } 
  if (com.has_value()) {
    return com.value();
  } else {
    particle sum_particle = zero_particle( dimensionality() );
    double sum_weight{0.};
    for ( auto &d : subdivisions ) {
      particle p = d.center_of_mass();
      auto w = p.weight();
      sum_weight += w;
      sum_particle = sum_particle + p * w;
    }
    com = sum_particle/sum_weight;
    return com.value();
  }
};

particle maybe_partitioned_box::center_of_mass() const {
  if ( auto box_content = get_if<box>(&contents); box_content )
    return (*box_content) . center_of_mass();
  else if ( auto div_content = get_if<box>(&contents); div_content )
    return (*div_content) . center_of_mass();
  else throw("incomprehensible partitioned box");
};

double particle::force_on( const particle &p ) const {
  return weight()*p.weight() / distance(p);
};

void partitioned_box::add( const box &b ) {
  subdivisions.push_back( maybe_partitioned_box(b) );
  com = {};
};

double box::force_on( const particle &p /* , double break_ratio */ ) const {
  double f{0};
  const auto &com = center_of_mass();
  double ratio = p.distance( com ) / bb_size;
  // if (break_ratio>0 && ratio<break_ratio) {
  //   f = com.force_on(p);
  // } else {
    for ( const auto &other : particles() ) {
      f += other.force_on(p);
    }
    //  }
  return f;
};

double partitioned_box::force_on( const particle &p ) const {
  double f{0.};
  for ( const auto &d : subdivisions )
    f += d.force_on(p);
  return f;
};

double maybe_partitioned_box::force_on( const particle &p /*,double break_ratio */ ) const {
  return std::visit( compute_force_on{p}, contents );
};

string particle::as_string() const {
  stringstream ss;
  ss << "(";
  for ( const auto &c : coordinates )
    ss << c << ",";
  ss << "):" << weight();
  return ss.str();
};

string box::as_string() const {
  stringstream ss;
  ss << "{ ";
  for ( const auto &p : _particles )
    ss << p.as_string() << ", ";
  ss << "}";
  return ss.str();
};

string partitioned_box::as_string() const {
  stringstream ss;
  ss << "[ ";
  for ( auto &d : subdivisions )
    ss << d.as_string() << ", ";
  ss << "]";
  return ss.str();
};

string maybe_partitioned_box::as_string() const {
  if ( auto box_content = get_if<box>(&contents); box_content )
    return (*box_content) . as_string();
  else if ( auto div_content = get_if<box>(&contents); div_content )
    return (*div_content) . as_string();
  else throw("incomprehensible partitioned box");
};

