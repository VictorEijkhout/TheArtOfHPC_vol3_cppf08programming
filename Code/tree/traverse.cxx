/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2017-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** traverse.cxx : speed measurement
 ****
 ****************************************************************/

#include <cmath>

#include <iostream>
using std::cin;
using std::cout;
#include <sstream>
using std::stringstream;

#include <chrono>

#include <memory>
using std::make_shared;
using std::shared_ptr;
using std::make_unique;
using std::unique_ptr;

#include <random>
#include <string>

#include <vector>
using std::vector;

class Node_shared {
private:
  int datavalue{0};
  shared_ptr<Node_shared>
    tail_ptr{nullptr};
public:
  Node_shared() {}
  Node_shared(int value)
    : datavalue(value) {};
  int value() { return datavalue; };
  bool has_next() {
    return tail_ptr!=nullptr; };
  //codesnippet end
  void set_tail
      ( shared_ptr<Node_shared> tail ) {
    tail_ptr = tail; };
  int list_length() {
    if (!has_next()) return 1;
    else return 1+tail_ptr->list_length();
  };
  void append( shared_ptr<Node_shared> other ) {
    if (!has_next())
      set_tail(other);
    else 
      tail_ptr->append(other);
  };
  void insert( shared_ptr<Node_shared> other ) {
    if (!has_next())
      set_tail(other);
    else if (other->datavalue>tail_ptr->datavalue)
      tail_ptr->insert(other);
    else {
      other->set_tail(tail_ptr);
      set_tail(other);
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

class Node_shared_ref {
private:
  int datavalue{0};
  shared_ptr<Node_shared_ref>
    tail_ptr{nullptr};
public:
  Node_shared_ref() {}
  Node_shared_ref(int value)
    : datavalue(value) {};
  int value() { return datavalue; };
  bool has_next() {
    return tail_ptr!=nullptr; };
  //codesnippet end
  void set_tail
      ( shared_ptr<Node_shared_ref>& tail ) {
    tail_ptr = tail; };
  int list_length() {
    if (!has_next()) return 1;
    else return 1+tail_ptr->list_length();
  };
  void append( shared_ptr<Node_shared_ref>& other ) {
    if (!has_next())
      set_tail(other);
    else 
      tail_ptr->append(other);
  };
  void insert( shared_ptr<Node_shared_ref>& other ) {
    if (!has_next())
      set_tail(other);
    else if (other->datavalue>tail_ptr->datavalue)
      tail_ptr->insert(other);
    else {
      other->set_tail(tail_ptr);
      set_tail(other);
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

class Node_unique {
private:
  int datavalue{0};
  unique_ptr<Node_unique>
    tail_ptr{nullptr};
public:
  Node_unique() {}
  Node_unique(int value)
    : datavalue(value) {};
  int value() { return datavalue; };
  bool has_next() {
    return tail_ptr!=nullptr; };
  //codesnippet end
  void set_tail
      ( unique_ptr<Node_unique> tail ) {
    tail_ptr = std::move(tail); };
  int list_length() {
    if (!has_next()) return 1;
    else return 1+tail_ptr->list_length();
  };
  void append( unique_ptr<Node_unique> other ) {
    if (!has_next())
      set_tail( std::move(other) );
    else 
      tail_ptr->append( std::move(other) );
  };
  void insert( unique_ptr<Node_unique> other ) {
    if (!has_next())
      set_tail( std::move(other) );
    else if (other->datavalue>tail_ptr->datavalue)
      tail_ptr->insert( std::move(other) );
    else {
      other->set_tail( std::move(tail_ptr) );
      set_tail( std::move(other) );
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

  using myclock = std::chrono::steady_clock ;

  const int N = 30000;
  vector<int> values(N);
  std::uniform_int_distribution<> distribution(0,10*N);
  std::default_random_engine generator;
  for ( auto& v : values )
    v = distribution(generator);

  {
    auto start_time = myclock::now();
    auto head = Node_shared(-1);
    for ( auto v : values ) {
      head.insert( make_shared<Node_shared>(v) );
    }
    auto duration = myclock::now()-start_time;
    auto microsec_duration =
      std::chrono::duration_cast<std::chrono::microseconds>(duration);
    int usec = microsec_duration.count();
    cout << "Prepping memory: " << usec << " usec\n";
  }

  {
    auto start_time = myclock::now();
    auto head = Node_shared(-1);
    for ( auto v : values ) {
      head.insert( make_shared<Node_shared>(v) );
    }
    auto duration = myclock::now()-start_time;
    auto microsec_duration =
      std::chrono::duration_cast<std::chrono::microseconds>(duration);
    int usec = microsec_duration.count();
    cout << "Shared pointers: " << usec << " usec\n";
  }

  {
    auto start_time = myclock::now();
    auto head = Node_shared_ref(-1);
    for ( auto v : values ) {
      auto new_node = make_shared<Node_shared_ref>(v);
      head.insert( new_node );
    }
    auto duration = myclock::now()-start_time;
    auto microsec_duration =
      std::chrono::duration_cast<std::chrono::microseconds>(duration);
    int usec = microsec_duration.count();
    cout << "Shared by ref  : " << usec << " usec\n";
  }

  {
    auto start_time = myclock::now();
    auto head = Node_unique(-1);
    for ( auto v : values ) {
      head.insert( make_unique<Node_unique>(v) );
    }
    auto duration = myclock::now()-start_time;
    auto microsec_duration =
      std::chrono::duration_cast<std::chrono::microseconds>(duration);
    int usec = microsec_duration.count();
    cout << "Unique pointers: " << usec << " usec\n";
  }

  return 0;
}

