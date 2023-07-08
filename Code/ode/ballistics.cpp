/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2022 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** ballistics.cxx : ENIAC firing tables 
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <functional>
using std::function;

#include <vector>
using std::vector;

class Integrator {
protected:
  function< double(double) > f;
  double stepsize,currentx,integrated{0};
public:
  Integrator( function< double(double) > f, double s,double init=0)
    : f(f), stepsize(s),currentx(init) {
  };
  virtual double nextstep() = 0;
};

class ForwardIntegrator : public Integrator {
public :
  ForwardIntegrator( function< double(double) > f,double s,double init=0.)
    : Integrator(f,s,init) {};
  double nextstep() { // F1 - F0 / s = f(0)
    integrated = integrated + stepsize * f(currentx);
    currentx += stepsize;
    return integrated;
  };
  double to(double endpoint) {
    while (currentx<endpoint)
      nextstep();
    return integrated;
  };
};

class BackwardIntegrator : public Integrator {
public :
  BackwardIntegrator( function< double(double) > f,double s,double init=0.)
    : Integrator(f,s,init) {};
  double nextstep() { // F1 - F0 / s = f(1)
    currentx += stepsize;
    integrated = integrated + stepsize * f(currentx);
    return integrated;
  };
  double to(double endpoint) {
    while (currentx<endpoint)
      nextstep();
    return integrated;
  };
};

int main() {

  {
    double stepsize = .01;
    auto integrate_linear =
      ForwardIntegrator( [] (double x) { return x*x; }, stepsize );
    double int1 = integrate_linear.to(1.);
    double int2 = integrate_linear.to(2.);
    cout << "to 1: " << int1 << ", to 2: " << int2 << '\n';
  }
  {
    double stepsize = .01;
    auto integrate_linear =
      BackwardIntegrator( [] (double x) { return x*x; }, stepsize );
    double int1 = integrate_linear.to(1.);
    double int2 = integrate_linear.to(2.);
    cout << "to 1: " << int1 << ", to 2: " << int2 << '\n';
  }

  return 0;
}
