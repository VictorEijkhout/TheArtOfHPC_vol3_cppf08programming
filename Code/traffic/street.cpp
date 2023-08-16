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
using std::string;
#include <vector>
using std::vector;
// #include <memory>
// using std::make_shared;

#include <thread>

// #include <format>
// using std::format;

#include "traffic_lib.hpp"
using fmt::format,fmt::print;

#include "catch2/catch_all.hpp"
bool global_do_vis = false;

lTEST_CASE( "car positions","[01]" ) {
  coordinate origin{0,0}, unit_vector{1,0};

  // test displacement function
  REQUIRE( displacement( origin,unit_vector,unit_vector) > 0 );
  REQUIRE( displacement( unit_vector,origin,unit_vector) < 0 );

  // make two cars
  REQUIRE_NOTHROW( Car( {.location=origin} ) );
  Car one( {.location=origin} );
  REQUIRE_NOTHROW( origin+unit_vector );
  auto ahead = origin+unit_vector;
  REQUIRE_NOTHROW( Car( {.location=ahead} ) );

  // see that the second is beyond the first, and not vv
  Car overtake( {.location=ahead} );
  REQUIRE_NOTHROW( overtake.collides_with( one,unit_vector ) );
  REQUIRE        ( overtake.collides_with( one,unit_vector ) );
  REQUIRE        ( not one.collides_with( overtake,unit_vector ) );
}

TEST_CASE( "brake distance","[02]" ) {
  float speed = 10;
  coordinate origin{0,0}, unit_vector{1,0};
  float accel = speed/5;  
  Car moving( { .speed=speed, .goal_speed=0.f, .location=origin, .acceleration=accel } );
  for ( int step=0; step<20 and moving.speed()>0; ++step ) {
    float speed = moving.speed();
    //    cout << "current speed: " << speed << '\n';
    moving.determine_next_state();
    moving.progress(unit_vector);
    float new_speed = moving.speed();
    REQUIRE( new_speed==Catch::Approx(speed-accel) );
  }
  auto new_location = moving.location();
  cout << "moved by: " << displacement(origin,new_location) << '\n';
}

TEST_CASE( "street","[11]" ) {
  float length{20.f};
  // street from two coordinates on the x axis
  coordinate point_a(0.f,0.f), point_b(length,0.f);
  REQUIRE_NOTHROW( Street(point_a,point_b) );
  Street main_street(point_a,point_b);
  REQUIRE_NOTHROW( main_street.unit_vector() );
  const auto [dx,dy] = main_street.unit_vector();
  REQUIRE( dy==0.f );
  REQUIRE( dx==Catch::Approx(1.f) );
  REQUIRE_NOTHROW( main_street.length() );
  REQUIRE( main_street.length()==Catch::Approx(length) );
}

TEST_CASE( "car on street","[12]" ) {
  float length{20.f};
  // street from two coordinates on the x axis
  coordinate point_a(0.f,0.f), point_b(length,0.f);
  Street main_street(point_a,point_b);

  // test if a car is on the road or beyond
  auto car_a = make_shared<Car>( coordinate{ .001f,.0f } );
  REQUIRE_NOTHROW( main_street.beyond( car_a ) );
  REQUIRE( not main_street.beyond( car_a ) );
  auto car_half = make_shared<Car>( coordinate(length/2,0.f) );
  REQUIRE_NOTHROW( main_street.beyond( car_half ) );
  REQUIRE( not main_street.beyond( car_half ) );
  //codesnipppet streettestbeyond
  auto car_far = make_shared<Car>( coordinate(length*2,0.f) );
  REQUIRE_NOTHROW( main_street.beyond( car_far ) );
  REQUIRE( main_street.beyond( car_far ) );
  //codesnipppet end
}

TEST_CASE( "car driving","[13]" ) {
  // street from two coordinates on the x axis
  Street main_street( coordinate(0.f,0.f),coordinate(40.f,0.f) );

  // insert a single car
  float speed{1.f};
  //codesnippet traffic1progress
  REQUIRE_NOTHROW( main_street.insert_with_speed(speed) );
  float time=0.f;
  for ( int t=0; t<static_cast<int>(main_street.length()); ++t ) { // one extra step
    INFO( format( "at t={}, #cars={}",t,main_street.size() ) );
    if ( main_street.empty() ) break;

    if (global_do_vis) {
      // animation:
      main_street.display();
      std::this_thread::sleep_for( seconds{2}/10. );
      cout << '\n';
      printf( "%c[1A",(char)27); // line up again.
    }
    
    auto car = main_street.at(0);
    REQUIRE( car->speed()==Catch::Approx(speed) );
    REQUIRE_NOTHROW( main_street.progress() );
  }
  REQUIRE( main_street.empty() );
  //codesnippet end
}

TEST_CASE( "equal spacing","[14]" ) {
  // street from two coordinates on the x axis
  Street main_street( coordinate(0.f,0.f),coordinate(40.f,0.f) );

  float speed{1.f};
  main_street.insert_with_speed(speed);
  for ( int t=0; t<static_cast<int>(main_street.length()); ++t ) { // one extra step
    if ( main_street.empty() ) break;

    if (global_do_vis) {
      // animation:
      main_street.display();
      std::this_thread::sleep_for( seconds{2}/10. );
      cout << '\n';
      printf( "%c[1A",(char)27); // line up again.
    }

    if ( main_street.is_clear_for_new_car(speed) and main_street.size()<5 ) {
      // introduce new car:
      main_street.insert_with_speed(speed);
    }
    for ( auto c : main_street ) {
      INFO( c->as_string() );
      REQUIRE( c->speed()==Catch::Approx(speed) );
    }
	       
    REQUIRE( main_street.progress() );
  }
};

TEST_CASE( "collision detection","[21]" ) {
  Street main_street( coordinate(0.f,0.f),coordinate(40.f,0.f) );
  
  float speed{1.f};
  main_street.insert_with_speed(speed);
  main_street.front()->set_render('1');
  bool safe_step{false};
  // car #1 : no problem
  REQUIRE_NOTHROW( safe_step = main_street.progress() );
  REQUIRE( safe_step );
  // car #2 is speeding!
  // NOTE the choice of this factor 4 is not very scientific
  REQUIRE_NOTHROW( main_street.insert_with_speed(4*speed) );
  main_street.front()->set_render('2');
  INFO( "before: " << main_street.as_string() );
  SECTION( "external force" ) {
    bool collisions{false};
    REQUIRE_NOTHROW( main_street.front()->determine_next_state() );
    REQUIRE_NOTHROW( main_street.front()->progress( main_street.unit_vector() ) );
    INFO( "after : " << main_street.as_string() );
    REQUIRE_NOTHROW( collisions = main_street.detect_collisions() );
    REQUIRE( collisions );
  }
  SECTION( "internal mechanisms" ) {
    REQUIRE_NOTHROW( safe_step = main_street.progress() );
    INFO( "after : " << main_street.as_string() );
    REQUIRE( not safe_step );
  } 
}

TEST_CASE( "collision scenario","[22]" ) {
  Street main_street( coordinate(0.f,0.f),coordinate(40.f,0.f) );
  
  float speed{1.f};
  main_street.insert_with_speed(speed);
  bool collision{false};
  for ( int t=0; t<static_cast<int>(main_street.length()); ++t ) {
    if ( main_street.empty() ) break;

    if ( main_street.is_clear_for_new_car( .25 * speed ) and main_street.size()<2 ) {
      // introduce new car:
      main_street.insert_with_speed(speed);
      main_street.at(0)->set_render('o');
      main_street.at(0)->set_risk_tolerance(2.5);
    }

    if (global_do_vis) {
      // animation:
      main_street.display();
      std::this_thread::sleep_for( seconds{2}/10. );
      cout << '\n';
      printf( "%c[1A",(char)27); // line up again.
    }

    if ( t==15 ) {
      main_street.back()->set_forced_speed( vector<float>(6, .0f * speed) );
    }
    bool safe_step{false};
    REQUIRE_NOTHROW( safe_step = main_street.progress() );
    collision = collision or not safe_step;
  }
  REQUIRE( collision );
}

TEST_CASE( "hit the brakes","[23]" ) {
  // street from two coordinates on the x axis
  Street main_street( coordinate(0.f,0.f),coordinate(80.f,0.f) );

  // insert a single car
  float speed{1.f};
  main_street.insert_with_speed(speed);
  int pumped = -1;
  for ( int t=0; t<static_cast<int>(main_street.length()); ++t ) { // one extra step
    if ( main_street.empty() ) break;

    if ( main_street.is_clear_for_new_car(speed)
	 and main_street.size()<20 ) {
      // introduce new car:
      main_street.insert_with_speed(speed);
    }
      
    if ( t==15 ) {
      main_street.back()->set_forced_speed( vector<float>(16, .25f * speed) );
    }

    if (global_do_vis) {
      // animation:
      main_street.display();
      std::this_thread::sleep_for( seconds{2}/10. );
      cout << '\n';
      printf( "%c[1A",(char)27); // line up again.
    }

    main_street.progress();
  }
  cout << '\n';
};

int main( int argc,char const * const * argv ) {

  Catch::Session session; // there can only be one session

  using namespace Catch::Clara;
  int vis=0;
  auto cli = session.cli()
    | Opt( vis,"vis") ["-v"]["--vis"] ("turn on visualization");
  session.cli( cli );

  int returnCode = session.applyCommandLine( argc, argv );
  if ( returnCode != 0 )
    return returnCode;

  //  if set on the command line then 'vis' is now set at this point
  if ( vis>0 )
    global_do_vis = true;

  session.run();

  return 0;
}
