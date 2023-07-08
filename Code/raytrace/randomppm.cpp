/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** randomppm.cxx : generate random ppm file
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include "imglib.hpp"

int main() {

    int width=256,height=256;
    cout << "P3\n";
    cout << width << " " << height << '\n';
    cout << 256 << '\n';
    for ( int iy=height-1; iy>=0; iy-- ) {
	for ( int ix=0; ix<width; ix++ ) {
	    float rfraction = static_cast<float>(ix) / (width-1);
	    float gfraction = static_cast<float>(iy) / (height-1);
	    float bfraction  = 0.25;
	    color c{rfraction,gfraction,bfraction};
	    // unsigned short r = static_cast<unsigned short>( 255.9 * rfraction );
	    // unsigned short g = static_cast<unsigned short>( 255.9 * gfraction );
	    // unsigned short b = static_cast<unsigned short>( 255.9 * bfraction );
	    // cout << r << " " << g << " " << b << '\n';
	    cout << c << '\n';
	}
    }
    return 0;
}
