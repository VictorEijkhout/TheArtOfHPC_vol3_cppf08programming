/****************************************************************
 ****
 **** This code is part of the book
 **** Introduction to High Performance Scientific Programming
 **** by Victor Eijkhout eijkhout@tacc.utexas.edu
 **** copyright 2010-2023
 ****
 **** ellipse.cpp : minimization by steepest descent of a quadratic function
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
using std::endl;
#include <iomanip>
using std::fixed;
using std::setprecision;

#include <cmath>
double pi() { return std::atan(1)*4; };
#include <cassert>

#include "cxxopts.hpp"
#include "catch2/catch_all.hpp"

/*
 * included libraries for this application
 */
#include "vectorlib.h"
#include "minimlib.h"

TEST_CASE( "circle","[1]" ) {
  INFO( "Evaluate circle" );
  ellipse circle( valuevector( {1.,1.} ),valuevector( {0.,0.} ) );

  decltype( circle.eval( valuevector( { 0.,0. } ) ) ) should_be_zero;
  REQUIRE_NOTHROW( should_be_zero = circle.eval( valuevector( { 0.,0. } ) ) );
  REQUIRE( should_be_zero ==Catch::Approx(0.) );
}

TEST_CASE( "shifted circle","[2]" ) {
  ellipse circle( valuevector( {1.,1.} ),valuevector( {1.,1.} ) );

  decltype( circle.eval( valuevector( { 1.,1. } ) ) )  should_be_zero;
  REQUIRE_NOTHROW( should_be_zero = circle.eval( valuevector( { 1.,1. } ) ) );
  REQUIRE( should_be_zero ==Catch::Approx(0.) );

  decltype( circle.eval( valuevector( { 2.,2. } ) ) )  should_be_two;
  REQUIRE_NOTHROW( should_be_two = circle.eval( valuevector( { 2.,2. } ) ) );
  REQUIRE( should_be_two == Catch::Approx( 2. ) );
}

TEST_CASE( "Gradient in circle","[3]" ) {
  ellipse circle( valuevector( {1.,1.} ),valuevector( {0.,0.} ) );

  auto should_point_right = circle.grad( valuevector( { 1.,0. } ) );
  cout << "should point right (size 2): "
       << should_point_right.at(0) << "," << should_point_right.at(1)
       << endl;
  auto should_point_up = circle.grad( valuevector( { 0.,1. } ) );
  cout << "should point up (size 2): "
       << should_point_up.at(0) << "," << should_point_up.at(1)
       << endl;
  cout << endl;
}

TEST_CASE( "Gradient in shifted circle","[4]" ) {
  ellipse circle( valuevector( {1.,1.} ),valuevector( {1.,1.} ) );

  decltype( circle.grad( valuevector( { 2.,1. } ) ) ) should_point_right;
  REQUIRE_NOTHROW( should_point_right = circle.grad( valuevector( { 2.,1. } ) ) );
  REQUIRE( should_point_right.at(0)>0. );
  REQUIRE( should_point_right.at(1)==Catch::Approx(0.) );

  decltype( circle.grad( valuevector( { 1.,2. } ) ) ) should_point_up;
  REQUIRE_NOTHROW( should_point_up = circle.grad( valuevector( { 1.,2. } ) ) );
  REQUIRE( should_point_up.at(0)==Catch::Approx(0.) );
  REQUIRE( should_point_up.at(1)>0. );
}

int main(int argc,char **argv) {

  /*
   * Unit tests
   */
  Catch::Session session; // there can only be one session

  // using namespace Catch::Clara;
  // int vis;
  // auto cli = session.cli()
  //     | Opt( vis,"vis") ["-v"]["--vis"] ("turn on visualization");
  // session.cli( cli );

  //  int returnCode = session.applyCommandLine( argc, argv );
  session.run( argc,argv );

#if 0
  /*
   * Run options
   */
  cxxopts::Options options("ellipse", "Gradient descent on an ellipse");
  options.add_options()
    ("t,testrun", "test run number, zero for all, default none",
     cxxopts::value<int>()->default_value("-1"))
    ("h,help","usage information")
    ;
  auto result = options.parse(argc, argv);
  if (result.count("help")) {
    cout << options.help() << endl;
    return 1;
  }
  auto testrun = result["t"].as<int>();

  /*
   * Tests to be parsed
   */
  if (testrun==5) {
    cout << "Search in a perfect circle" << endl;
    ellipse circle
      ( valuevector( {1.,1.} ),valuevector( {0.,0.} ) );
    valuevector search_point( { 1.,1. } );
    auto value = circle.eval(search_point);
    for (int step=0; step<5 and value>.0001; step++) {
      cout << "Step " << step << " "
           << "(" << search_point.at(0)
           << "," << search_point.at(1) << "); "
           << "value: " << value << endl;
      auto grad = circle.grad(search_point);
      cout << grad.at(0) << "," << grad.at(1) << endl;
      search_point -= grad*.25;
      value = circle.eval(search_point);
    }
    cout << endl;
  }

  if (testrun==6) {
    cout << "Search in a skinny ellipse" << endl;
    ellipse circle
      ( valuevector( {1.,.1} ),valuevector( {0.,0.} ) );
    valuevector search_point( { 1.,1. } );
    for (int step=0; step<5; step++) {
      auto value = circle.eval(search_point);
      cout << "Step " << step << " "
	   << "(" << search_point.at(0) << "," << search_point.at(1) << "); "
	   << "value: " << value << endl;
      auto grad = circle.grad(search_point);
      auto fraction = .25;
      while ( circle.eval( search_point - grad*fraction ) > value ) {
	fraction /= 2.;
	cout << ".. backtrack to " << fraction << endl;
      }
      search_point -= grad*fraction;
    }
    cout << endl;
  }

  if (testrun==7) {
    cout << "Optimal stepsize in a perfect circle" << endl;
    cout << "  DescentCircle" << endl;
    //codesnippet descentcircle
    ellipse circle
      ( valuevector( {1.,1.} ),valuevector( {0.,0.} ) );
    valuevector search_point( { 1.,1. } );
    auto value = circle.eval(search_point);

    auto new_point = steepest_descent_step(circle,search_point);

    auto new_value = circle.eval(new_point);
    cout << "Starting point "
	 << "(" << search_point.at(0)
	 << "," << search_point.at(1) << "); "
	 << "with value: " << value << "\n"
	 << "  becomes "
	 << "(" << new_point.at(0)
	 << "," << new_point.at(1) << "); "
	 << "with value: " << new_value << endl;
    //codesnippet end
    cout << "  descentcircle" << endl;
    cout << endl;
  }

  if (testrun==8) {
    cout << "Optimal stepsize in a skinny ellipse" << endl;
    cout << "  DescentEllipse" << endl;
    //codesnippet descentellipse
    ellipse circle( valuevector( {1.,.1} ),valuevector( {0.,0.} ) );
    valuevector search_point( { 1.,1. } );
    auto value = circle.eval(search_point);
    for (int step=0; step<5 and value>.0001; step++) {

      auto new_point = steepest_descent_step(circle,search_point);

      auto new_value = circle.eval(new_point);
      cout << "Starting point " << fixed
  	 << "(" << setprecision(4) << search_point.at(0)
         << "," << setprecision(4) << search_point.at(1) << "); "
         << "with value: " << value << "\n"
  	 << "  becomes "
  	 << "(" << setprecision(4) << new_point.at(0)
         << "," << setprecision(4) << new_point.at(1) << "); "
  	 << "with value: " << new_value << endl;
      search_point = new_point; value = new_value;
    }
    //codesnippet end
    cout << "  descentellipse" << endl;
    cout << endl;
  }

  if (testrun==9) {
    cout << "Stochastic descent in a skinny ellipse" << endl;
    ellipse circle( valuevector( {1.,.1} ),valuevector( {0.,0.} ) );
    auto dim = circle.dimension();

    valuevector search_point( { 1.,1. } );
    auto value = circle.eval(search_point);

    for (int step=0; step<5 and value>.00001; step++) {
      for (int idim=0; idim<dim and value>.00001; idim++) {

	auto new_point = stochastic_descent_step(circle,search_point,idim);

	auto new_value = circle.eval(new_point);
	cout << "Step " << step << ", direction " << idim << " "
	     << "point (" << search_point.at(0) << "," << search_point.at(1) << "); "
	     << "with value: " << value
	     << ", becomes "
	     << "(" << new_point.at(0) << "," << new_point.at(1) << "); "
	     << "with value: " << new_value << endl;
	search_point = new_point; value = new_value;
      }
    }
    cout << endl;
  }

  if (testrun==10) {
    cout << "Stochastic descent in a rotated ellipse" << endl;
    rotated_ellipse circle( valuevector( {1.,.1} ),valuevector( {0.,0.} ), pi()/6. );
    auto dim = circle.dimension();

    valuevector search_point( { 1.,1. } );
    auto value = circle.eval(search_point);

    for (int step=0; step<15 and value>.00001; step++) {
      for (int idim=0; idim<dim and value>.00001; idim++) {

	auto new_point = stochastic_descent_step(circle,search_point,idim,.2);

	auto new_value = circle.eval(new_point);
	cout << "Step " << step << ", direction " << idim << " "
	     << "point (" << search_point.at(0) << "," << search_point.at(1) << "); "
	     << "with value: " << value
	     << ", becomes "
	     << "(" << new_point.at(0) << "," << new_point.at(1) << "); "
	     << "with value: " << new_value << endl;
	search_point = new_point; value = new_value;
      }
    }
    cout << endl;
  }
#endif

  return 0;
}
