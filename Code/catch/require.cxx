/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** cxx : example
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#define CATCH_CONFIG_MAIN
#include "catch2/catch_all.hpp"

//codesnippet catchfivefun
int five() { return 5; }
//codesnippet end

//codesnippet catchtestyes
TEST_CASE( "needs to be 5","[1]" ) {
    REQUIRE( five()==5 );
}
//codesnippet end

//codesnippet catchtestno
TEST_CASE( "not six","[2]" ) {
    REQUIRE( five()==6 );
}
//codesnippet end

//codesnippet catchevenfun
void even( int e ) {
    if (e%2==1) throw(1);
    cout << "Even number: "
         << e << '\n';
}
//codesnippet end

//codesnippet catchtesteven
TEST_CASE( "even fun","[3]" ) {
    REQUIRE_NOTHROW( even(2) );
    REQUIRE_THROWS( even(3) );
}
//codesnippet end

//codesnippet catchtestgen
TEST_CASE( "even set","[4]" ) {
    int e = GENERATE( 2,4,6,8 );
    REQUIRE_NOTHROW( even(e) );
}
//codesnippet end


