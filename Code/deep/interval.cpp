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

  data_vector
    indata  ( vector<float>{1,2,3,6,7,8,11,12,13,14,15,21,22,23,24,25,26} ),
    values  ( vector<float>{0,0,0,0,0,0,01,01,01,01,01,00,00,00,00,00,00} ),
    outdata ( values.size() ),
    testdata( vector<float>{ -1.5,3.5,4.5,6.5,9.5, 11.5,12.5,15.5,16,5, 24.5,25.5,31,5 } ),
    testout ( testdata.size() )
    ;
  auto net = network( {indata.size(),outdata.size() } );
  net.set_learning_rate(.05);
  cout << "Network with " << net.depth() << " layers" << '\n';
  cout << '\n';

  cout << "################" << '\n';
  cout << "Input data: " << indata.as_string() << '\n';
  cout << "values    : " << values.as_string() << '\n';

  for (int step=0; step<10; step++) {
    cout << "################ Step " << step << " ################" << '\n';
    net.apply(indata,outdata);
    auto c = net.cost(outdata,values);
    cout << "error: " << c << '\n';
    net.apply(testdata,testout);
    cout << "apply on test data: " << testout.as_string() << '\n';
    if (c<0) break;
    net.backpass(indata,outdata,values);
  }

  return 0;
}
