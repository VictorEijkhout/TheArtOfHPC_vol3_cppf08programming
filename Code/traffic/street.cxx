/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** street.cxx : simple street simulation
 ****
 ****************************************************************/

#include <chrono>
using std::chrono::seconds;
#include <iostream>
using std::cout,std::cin;

#include <thread>

// #include <format>
// using std::format;

#include "traffic_lib.h"

#include "catch2/catch_all.hpp"

TEST_CASE( "street","[01]" ) {
  float length{20.f};
  // street from two coordinates on the x axis
  coordinate point_a(0.f,0.f), point_b(length,0.f);
  REQUIRE_NOTHROW( Street(point_a,point_b) );
  Street main(point_a,point_b);
  REQUIRE_NOTHROW( main.unit_vector() );
  const auto [dx,dy] = main.unit_vector();
  REQUIRE( dy==0.f );
  REQUIRE( dx==Catch::Approx(1.f) );
  REQUIRE_NOTHROW( main.length() );
  REQUIRE( main.length()==Catch::Approx(length) );
}

TEST_CASE( "car on street","[02]" ) {
  float length{20.f};
  // street from two coordinates on the x axis
  coordinate point_a(0.f,0.f), point_b(length,0.f);
  Street main(point_a,point_b);

  // test if a car is on the road or beyond
  Car car_a( coordinate( .001f,.0f ) );
  REQUIRE_NOTHROW( main.beyond( car_a ) );
  REQUIRE( not main.beyond( car_a ) );
  Car car_half( coordinate(length/2,0.f) );
  REQUIRE_NOTHROW( main.beyond( car_half ) );
  REQUIRE( not main.beyond( car_half ) );
  Car car_far( coordinate(length*2,0.f) );
  REQUIRE_NOTHROW( main.beyond( car_far ) );
  REQUIRE( main.beyond( car_far ) );
}

TEST_CASE( "car driving","[03]" ) {
  // street from two coordinates on the x axis
  Street main( coordinate(0.f,0.f),coordinate(40.f,0.f) );

  // insert a single car
  float speed{1.f};
  REQUIRE_NOTHROW( main.insert( Car(speed) ) );
  float time=0.f;
  for ( int t=0; t<static_cast<int>(main.length()); t++ ) { // one extra step
    if ( main.empty() ) break;
    const auto& car = main.at(0);
    REQUIRE( car.speed()==Catch::Approx(speed) );
    //    cout << "t=" << t << ": " << car.as_string() << '\n';
    REQUIRE_NOTHROW( main.progress() );
  }
  REQUIRE( main.empty() );
}

TEST_CASE( "equal spacing","[04]" ) {
  // street from two coordinates on the x axis
  Street main( coordinate(0.f,0.f),coordinate(40.f,0.f) );

  // insert a single car
  float speed{1.f};
  main.insert( Car(speed) );
  for ( int t=0; t<static_cast<int>(main.length()); t++ ) { // one extra step
    if ( main.empty() ) break;

    if ( main.clear_for_new_car(speed) and main.size()<2 )
      // introduce new car:
      main.insert( Car(speed) );
    for ( auto c : main ) {
      INFO( c.as_string() );
      REQUIRE( c.speed()==Catch::Approx(speed) );
    }
	       
    main.progress();
  }
};

void drive_animation() {
  // street from two coordinates on the x axis
  Street main( coordinate(0.f,0.f),coordinate(40.f,0.f) );

  // insert a single car
  float speed{1.f};
  main.insert( Car(speed) );
  float time=0.f;
  for ( int t=0; t<static_cast<int>(main.length()); t++ ) { // one extra step
    if ( main.empty() ) break;

    // animation:
    main.display();
    std::this_thread::sleep_for( seconds{2}/10. );
    cout << '\n';
    printf( "%c[1A",(char)27); // line up again.

    main.progress();
  }
};

void multiple_animation() {
  // street from two coordinates on the x axis
  Street main( coordinate(0.f,0.f),coordinate(40.f,0.f) );

  // insert a single car
  float speed{1.f};
  main.insert( Car(speed) );
  for ( int t=0; t<static_cast<int>(main.length()); t++ ) { // one extra step
    if ( main.empty() ) break;

    if ( main.displacement( main.front().location() )
	 > safe_distance( main.front().speed() )
	 and main.size()<5 )
      // introduce new car:
      main.insert( Car(speed) );
      
    // animation:
    main.display();
    std::this_thread::sleep_for( seconds{2}/10. );
    cout << '\n';
    printf( "%c[1A",(char)27); // line up again.

    main.progress();
  }
};

void brake_animation() {
  // street from two coordinates on the x axis
  Street main( coordinate(0.f,0.f),coordinate(60.f,0.f) );

  // insert a single car
  float speed{1.f};
  main.insert( Car(speed) );
  int pumped = -1;
  for ( int t=0; t<static_cast<int>(main.length()); t++ ) { // one extra step
    if ( main.empty() ) break;

    if ( main.displacement( main.front().location() )
	 > safe_distance( main.front().speed() )
	 and main.size()<15 )
      // introduce new car:
      main.insert( Car(speed) );
      
    if ( pumped<0 // main.displacement( main.front().location() ) > 2
	 and main.size()>=7 ) {
      pumped = 10;
      main.back().speed() = .3f * speed;
    } else if (pumped>0) {
      pumped--;
    } else if (pumped==0) {
      // strictly speaking we should do this only once
      // but it doesn't hurt to do it every time after the pump
      main.back().speed() = speed;
    }
    //cout << main.back().as_string() << '\n';

    // animation:
    main.display();
    std::this_thread::sleep_for( seconds{2}/10. );
    cout << '\n';
    printf( "%c[1A",(char)27); // line up again.

    main.progress();
  }
  cout << '\n';
};

int main( int argc,char **argv ) {
  Catch::Session().run( argc, argv );

  int pause;
  // drive_animation();
  // cin >> pause;
  // multiple_animation();
  // cin >> pause;
  brake_animation();

  return 0;
}
