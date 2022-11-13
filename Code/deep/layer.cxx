/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2020 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** net.cxx : neural net tester
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;

#include <vector>
using std::vector;

#include "ml.hpp"

int main() {

  const int insize = 4, outsize = 2;

  {
    auto layer = network_layer(insize,outsize,0.,1.);
    data_vector
      indata(insize),
      outdata(outsize);
    cout << "Layer with zero coefficients and 1 bias" << '\n';
    layer.multiply(indata,outdata,true);
    cout << '\n';
  }

  {
    auto layer = network_layer(insize,outsize,1.);
    data_vector
      indata(insize,.5),
      outdata(outsize);
    cout << "Layer with 1 coefficients and 0 bias" << '\n';
    layer.multiply(indata,outdata,true);
    layer.activate(outdata);
    cout << "activation: " << outdata.as_string() << '\n';
    cout << '\n';
  }

  {
    auto layer = network_layer(insize,outsize,1.);
    data_vector
      indata(insize,.5),
      outdata(outsize);
    cout << "Layer with 1 coefficients and 0 bias" << '\n';
    layer.apply(indata,outdata,true);
    cout << '\n';
  }

  return 0;
}
