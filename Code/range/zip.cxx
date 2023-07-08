/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2023 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** zip.cxx : C++23 range zipping
 ****
 **** Inspired by https://www.cppstories.com/2023/view-zip/
 ****
 ****************************************************************/

#include <iostream>
using std::cout;
#include <sstream>
using std::stringstream;
#include <string>
using std::string;

#include <vector>
using std::vector;

//#include <ranges>
// zip not yet in gcc12
#include <range/v3/all.hpp>
#ifdef RANGES_V3_ALL_HPP
namespace rng = ranges;
#else
namespace rng = std::ranges;
#endif

#include <fmt/format.h>

int main()
{

  /*
   * old version
   */
  {
    vector a { 10, 20, 30, 40, 50 };
    vector<string> b { "ten", "twenty", "thirty", "fourty" };

    for (size_t i = 0; i < std::min(a.size(), b.size()); ++i)
      cout << fmt::format("{} -> {}\n", a[i], b[i]);

    // range version
    for (auto i : rng::iota_view{0ULL, std::min(a.size(), b.size())})
      cout << fmt::format("{} -> {}\n", a[i], b[i]);

    for (size_t i = 0; i < std::min(a.size(), b.size()); ++i) {
      const auto& num = a[i];
      const auto& name = b[i];
      cout << fmt::format("{} -> {}\n", name, num);
    }
  }

  /*
   * Range zip version
   */

  {
    cout << "Zip\n";
    //codesnippet rangeszip
    vector a { 10, 20, 30, 40, 50 };
    vector<string> b { "one", "two", "three", "four" };
        
    // zip in c++23, not yet in gcc12
    for (const auto& [num, name] : rng::views::zip(a, b))
      cout << fmt::format("{} -> {}\n", name, num);
    //codesnippet end
    cout << " .. zip\n";
  }

  return 0;
}
