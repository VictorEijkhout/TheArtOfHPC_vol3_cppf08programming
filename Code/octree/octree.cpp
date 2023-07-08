/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2020-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** octree.cxx : N-body
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include "octree_lib.hpp"

class tree {
private:
  variant<box,partitioned_box> one_box;
public:
};

int main() {

  particle p1234( {1.,2.,3.}, 4.5 );
  cout << "Particle: " << p1234.as_string() << '\n';

  particle p5678( {5.,6.,7.}, 8.9 );
  cout << "distance to " << p5678.as_string()
       << " = " << p1234.distance(p5678) << '\n';
  cout << '\n';

  {
    cout << "%%%% compute center of mass of a box %%%%" << '\n';
    particle one( {1.,1.},1. ), two( {2.,2.},1. );
    box line_box(2); line_box.add(one); line_box.add(two);
    auto center = line_box.center_of_mass();
    cout << "Box " << line_box.as_string()
	 << " center: " << center.as_string()
	 << '\n';
  }
  cout << '\n';

  {
    cout << "%%%% compute center of mass of a box %%%%" << '\n';
    box square_box(2);
    square_box.add( particle( {0,0},1) ); 
    square_box.add( particle( {0,1},1) ); 
    square_box.add( particle( {1,0},1) ); 
    square_box.add( particle( {1,1},1) ); 
    auto center = square_box.center_of_mass();
    cout << "Box " << square_box.as_string()
	 << " center: " << center.as_string()
	 << '\n';
  }
  cout << '\n';

  {
    cout << "%%%% compute center of mass of a partitioned box %%%%" << '\n';
    box left_box(2),right_box(2);
    left_box.add( particle( {0,0},1) ); 
    left_box.add( particle( {0,1},1) ); 
    right_box.add( particle( {1,0},1) ); 
    right_box.add( particle( {1,1},1) );
    partitioned_box boxes;
    boxes.add( left_box ); boxes.add( right_box );
    auto center = boxes.center_of_mass();
    cout << "Partitioned box " << boxes.as_string()
	 << " center: " << center.as_string()
	 << '\n';
  }
  cout << '\n';

  {
    cout << "%%%% split a box one-dimensionally %%%%" << '\n';
    particle one( {1.},1. ), two( {2.},1. );
    box line_box(1); line_box.add(one); line_box.add(two);
    partitioned_box partitioned_line( line_box );
    auto center = partitioned_line.center_of_mass();
    cout << "Partitioned line: " << partitioned_line.as_string()
	 << " center: " << center.as_string()
	 << '\n';
  }
  cout << '\n';

  {
    cout << "%%%% split a box two-dimensionally %%%%" << '\n';
    box square_box(2);
    square_box.add( particle( {0,0},1) ); 
    square_box.add( particle( {0,1},1) ); 
    square_box.add( particle( {1,0},1) ); 
    square_box.add( particle( {1,1},1) ); 
    partitioned_box partitioned_square( square_box );
    auto center = partitioned_square.center_of_mass();
    cout << "Partitioned square: " << partitioned_square.as_string()
	 << " center: " << center.as_string()
	 << '\n';
  }
  cout << '\n';

  {
    cout << "%%%% split incomplete box two-dimensionally %%%%" << '\n';
    box square_box(2);
    square_box.add( particle( {0,0},1) ); 
    square_box.add( particle( {1,1},1) ); 
    partitioned_box partitioned_square( square_box );
    auto center = partitioned_square.center_of_mass();
    cout << "Partitioned square: " << partitioned_square.as_string()
	 << " center: " << center.as_string()
	 << '\n';
  }
  cout << '\n';

  {
    cout << "%%%% force calculation %%%%" << '\n';
    box square_box(2);
    square_box.add( particle( {0,0},1) ); 
    square_box.add( particle( {0,1},1) ); 
    square_box.add( particle( {1,0},1) ); 
    square_box.add( particle( {1,1},1) ); 
    particle lowleft( {.25,.25},1. );
    auto f1 = square_box.force_on( lowleft );
    cout << "---- using c-o-m" << '\n';
    cout << "box " << square_box.as_string()
	 << " force on " << lowleft.as_string()
	 << ": " << f1 << '\n';
    cout << "---- breaking" << '\n';
    auto f2 = square_box.force_on( lowleft /* , 2. */ );
    cout << "box " << square_box.as_string()
	 << " force on " << lowleft.as_string()
	 << ": " << f2 << '\n';
  }
  cout << '\n';

  {
    cout << "%%%% force calculation %%%%" << '\n';
    box square_box(2);
    square_box.add( particle( {0,0},1) ); 
    square_box.add( particle( {0,1},1) ); 
    square_box.add( particle( {1,0},1) ); 
    square_box.add( particle( {1,1},1) ); 
    partitioned_box partitioned_square( square_box );
    particle lowleft( {.25,.25},1. );
    auto f = partitioned_square.force_on( lowleft );
    cout << "---- using c-o-m" << '\n';
    cout << "box " << partitioned_square.as_string()
	 << " force on " << lowleft.as_string()
	 << ": " << f << '\n';
    cout << "---- breaking" << '\n';
    cout << "box " << partitioned_square.as_string()
	 << " force on " << lowleft.as_string()
	 << ": " << f << '\n';
  }
  cout << '\n';

  {
    cout << "%%%% recursive split two-dimensionally %%%%" << '\n';

    box square_box(2);
    // lower left
    square_box.add( particle( {.11,.25},1) ); 
    square_box.add( particle( {.25,.25},1) ); 
    square_box.add( particle( {.50,.25},1) ); 
    // lower right
    square_box.add( particle( {.75,.25},1) ); 
    square_box.add( particle( {.99,.25},1) );
    // upper left
    square_box.add( particle( {.25,.75},1) );
    // upper right empty
    
    partitioned_box partitioned_square( square_box );
    auto center = partitioned_square.center_of_mass();
    cout << "Recursive square: " << partitioned_square.as_string()
	 << " center: " << center.as_string()
	 << '\n';
  }
  cout << '\n';

  return 0;
}
