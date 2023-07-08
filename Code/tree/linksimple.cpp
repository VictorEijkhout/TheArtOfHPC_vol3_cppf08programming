/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-9 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** linksimple.cxx : simple linked list using shared smart pointers
 ****
 ****************************************************************/

#include <cmath>

#include <iostream>
using std::cin;
using std::cout;
#include <sstream>
using std::stringstream;

#include <memory>
using std::make_shared;
using std::shared_ptr;
using std::enable_shared_from_this;

#include <string>

#include <vector>
using std::vector;

class Node {
private:
  int datavalue{0};
  shared_ptr<Node> tail_ptr{nullptr};
public:
  Node() {}
  Node(int value) { datavalue = value; };
  bool has_next() {
    return tail_ptr!=nullptr; };
  void set_tail( shared_ptr<Node> tail ) {
    tail_ptr = tail; };
  int value() { return datavalue; };
  /*
    Recursive function for computing the length of the list
    int list_length()
  */
  int list_length() {
    if (!has_next()) return 1;
    else return 1+tail_ptr->list_length();
  };
  /*
   Method for appending at the end of the list:
   void append( shared_ptr<Node> other )
  */
  void append( shared_ptr<Node> n ) {
    if (tail_ptr==nullptr)
      tail_ptr = n;
    else
      tail_ptr->append(n);
  };
  /*
   Method for inserting in the list, keeping it sorted:
   void insert_after( shared_ptr<Node> other )
   (does not work if `other' comes before the head of the list)
  */
  void insert_after( shared_ptr<Node> n ) {
    if (tail_ptr==nullptr) {
      if (n->datavalue>datavalue)
	tail_ptr = n;
      else throw;
    } else if (n->value()>tail_ptr->value())
      tail_ptr->insert_after(n);
    else {
      n->set_tail(tail_ptr); tail_ptr = n;
    }
  };
  std::string string() {
    stringstream strung;
    strung << datavalue;
    if (has_next()) {
      strung << "," << tail_ptr->string();
    }
    return strung.str();
  };
};

int main() {

  {
    cout << "Simple" << '\n';
    auto
      first = make_shared<Node>(23),
      second = make_shared<Node>(45);
    first->set_tail(second);
    cout << "List "
	 <<"<<" <<  first->string() << ">>"
         << " has length " << first->list_length()
	 << '\n';
    cout << '\n';
    cout << "simple" << '\n';
  }

  {
    cout << "Append" << '\n';
    auto
      first = make_shared<Node>(23),
      second = make_shared<Node>(45),
      third = make_shared<Node>(32);
    first->append(second);
    cout << "Append 23 & 45 gives <<"
	 << first->string() << ">>" << '\n';
    first->append(third);
    cout << "Append 32 gives <<"
	 << first->string() << ">>" << '\n';
    cout << '\n';
    cout << "append" << '\n';
  }

  {
    cout << "Insert" << '\n';
    auto
      first = make_shared<Node>(23),
      second = make_shared<Node>(45),
      third = make_shared<Node>(32);
    first->insert_after(second);
    cout << "Insert 45 on 23 gives <<"
	 << first->string() << ">>" << '\n';
    first->insert_after(third);
    cout << "Insert 32 gives <<"
	 << first->string() << ">>" << '\n';
    cout << '\n';
    cout << "insert" << '\n';
  }

  return 0;
}

