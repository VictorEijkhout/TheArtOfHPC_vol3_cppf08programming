/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** randomppm.cxx : generate random ppm file
 ****
 ****************************************************************/

#include <iostream>

class color {
 private:
    double values[3];
 public:
    color(double r,double g,double b)
	: values{r,g,b} {};
    auto& r() { return values[0]; };
    auto r() const { return values[0]; };
    auto& g() { return values[1]; };
    auto g() const { return values[1]; };
    auto& b() { return values[2]; };
    auto b() const { return values[2]; };
};

std::ostream& operator<<( std::ostream& os,const color& c ) {
    os << static_cast<unsigned short>( 255.99 * c.r() ) << " "
       << static_cast<unsigned short>( 255.99 * c.g() ) << " "
       << static_cast<unsigned short>( 255.99 * c.b() ) ;

    return os;
}
