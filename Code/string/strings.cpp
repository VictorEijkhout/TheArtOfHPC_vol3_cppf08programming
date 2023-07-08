/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** strings.cxx : exploration of the string class
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <string>
using std::string;

//codesnippet stringsuffix
void printfun( string s ) {
  cout << s << '\n';
}
void printfun_c( const string& s ) {
  cout << s << '\n';
}
//codesnippet end

int main() {

  cout << "Size" << '\n';
  //codesnippet stringsize
  string five_text{"fiver"};
  cout << five_text.size() << '\n';
  //codesnippet end
  cout << ".. size" << '\n';

  cout << "Push" << '\n';
  //codesnippet stringpush
  string five_chars;
  cout << five_chars.size() << '\n';
  for (int i=0; i<5; i++)
    five_chars.push_back(' ');
  cout << five_chars.size() << '\n';
  //codesnippet end
  cout << ".. push" << '\n';

  cout << "Add" << '\n';
  //codesnippet stringadd
  string my_string, space{" "};
  my_string = "foo";
  my_string += space + "bar";
  cout << my_string << ": " << my_string.size() << '\n';
  //codesnippet end
  cout << ".. add" << '\n';

  //  cout << my_string[ my_string.size()-1 ] << '\n';
  
  {
    cout << "Suffix\n";
    //codesnippet stringsuffix
    using namespace std::string_literals;
    printfun( "abc" );
    printfun( "def"s );
    printfun_c( "ghi" );
    printfun_c( "jkl"s );
    //codesnippet end
    cout << " .. suffix\n";
  }
  
  return 0;
}
