/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** datetime.cxx : using chrono date support
 ****
 ****************************************************************/

#include <iostream>
using std::cout;

#include <chrono>
// #include <format>
#include "fmt/format.h"

std::string get_current_time_and_date()
{
    auto const time = std::chrono::current_zone()
        ->to_local(std::chrono::system_clock::now());
    return fmt::format("{:%Y-%m-%d %X}", time);
}

int main() {

  cout << get_current_time_and_date() << '\n';

  return 0;
}
