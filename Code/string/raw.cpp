/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** raw.cxx : raw string literals
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <iomanip>
using std::setw;

#include <vector>
using std::vector;

#include <string>
using std::string;

int main() {

    cout << "Raw1\n";
    //codesnippet raw1
    cout << R"(string with }

{ \weird\ stuf)" << '\n';
    //codesnippet end
    cout << "raw1\n";

    cout << "Raw2\n";
    //codesnippet raw2
    cout << R"limit("(string with }

{ \weird\ stuff)")limit" << '\n';
    //codesnippet end
    cout << "raw2\n";

  return 0;
}
