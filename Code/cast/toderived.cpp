/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2018-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** toderived.cxx : cast to derived class
 ****
 ****************************************************************/

#include <iostream>
using namespace std; //::static_cast;

//codesnippet polybase
class Base {
public:
  virtual void print() = 0;
};
class Derived : public Base {
public:
  virtual void print() {
    cout << "Construct derived!"
         << '\n'; };
};
class Erived : public Base {
public:
  virtual void print() {
    cout << "Construct erived!"
         << '\n'; };
};
//codesnippet end

//codesnippet polybasefunc
void f( Base *obj ) {
  Derived *der =
    dynamic_cast<Derived*>(obj);
  if (der==nullptr)
    cout << "Could not be cast to Derived"
         << '\n';
  else
    der->print();
};
//codesnippet end

//codesnippet polywrong
void g( Base *obj ) {
  Derived *der =
    static_cast<Derived*>(obj);
  der->print();
};
//codesnippet end

int main() {
  
  {
    cout << "Polymain" << '\n';
    //codesnippet polycast
    Base *object = new Derived();
    f(object);
    Base *nobject = new Erived();
    f(nobject);
    //codesnippet end
    cout << "polymain" << '\n';
  }
 
  {
    cout << "Polybane" << '\n';
    //codesnippet polywrong
    Base *object = new Derived();
    g(object);
    Base *nobject = new Erived();
    g(nobject);
    //codesnippet end
    cout << "polybane" << '\n';
  }
 
  return 0;
}
