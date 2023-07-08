/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** fmtlib.cxx : exploring the C++20 fmt lib
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::ostream;
#include <sstream>
using std::stringstream;

#include <string>
using std::string;

class point{
private:
  double x,y;
public:
  point(double x,double y)
    : x(x),y(y) {};
  string as_string() const {
    stringstream ss;
    ss << "(" << x << "," << y << ")";
    return ss.str();
  }
};

#include <fmt/format.h>

//codesnippet fmtstream
template <> struct fmt::formatter<point> {
 constexpr
 auto parse(format_parse_context& ctx)
       -> decltype(ctx.begin()) {
   auto it = ctx.begin(),
     end = ctx.end();
   if (it != end && *it != '}')
     throw format_error("invalid format");
   return it;
  }
  template <typename FormatContext>
  auto format
      (const point& p, FormatContext& ctx)
        -> decltype(ctx.out()) {
    return format_to
      (ctx.out(),
       "{}", p.as_string());
  }
};
//codesnippet end

int main() {

  cout << "Basic\n";
  //codesnippet fmtbasic
  auto hello_string = fmt::format
    ("{} {}!","Hello","world");
  cout << hello_string << '\n';
  fmt::print
    ("{0}, {0} {1}!\n","Hello","world");
  //codesnippet end
  cout << "basic\n";

  cout << "Width\n";
  {
    //codesnippet fmtwidth
    for (int i=10; i<2000000000; i*=10)
      fmt::print("{:>6}\n",i);
    //codesnippet end
  }
  cout << "width\n";

  cout << "Leftpad\n";
  {
    //codesnippet fmtleftpad
    for (int i=10; i<2000000000; i*=10)
      fmt::print("{0:.>6}\n",i);
    //codesnippet end
  }
  cout << "leftpad\n";

  cout << "Base\n";
  {
    //codesnippet fmtbase
    fmt::print
      ("{0} = {0:b} bin,\n    {0:o} oct,\n    {0:x} hex\n",
       17);
    //codesnippet end
  }
  cout << "base\n";

  cout << "Stream\n";
  {
    //codesnippet fmtstream
    point p(1.1,2.2);
    fmt::print("{}\n",p);
    //codesnippet end
  }
  cout << "stream\n";

  return 0;
}

