/****************************************************************
 ****
 **** This file belongs with the course
 **** Introduction to Scientific Programming in C++/Fortran2003
 **** copyright 2016-2021 Victor Eijkhout eijkhout@tacc.utexas.edu
 ****
 **** fft.cxx : FFT code
 ****
 ****************************************************************/

#include <iostream>
using std::cin;
using std::cout;
#include <iomanip>
using std::setprecision;
#include <sstream>
using std::stringstream;

#include <complex>
#include <vector>
using std::vector;

#include <cassert>
#include <cmath>

#ifdef CPPSTANDARD20
#include <numbers>
static constexpr float pi = std::numbers::pi;
#else
static constexpr float pi = 3.141592653589793238462643383279502884;
#endif

namespace fft {
  template <typename T>
  class vector {
  private:
    std::vector<T> signal;
  public:
    vector(int n)
      : signal( std::vector<T>(n) ) {};
    // element access
    int samples() const { return signal.size(); };
    int size() const { return signal.size(); };
    auto &at(int i) { return signal.at(i); };
    const auto &at(int i) const { return signal.at(i); };
    // actual trig stuff
    void set_wave(int n=1) {
      using namespace std::complex_literals;
      int N = samples();
      for (int i=0; i<N; i++)
	signal.at(i) = std::exp( static_cast<float>( pi*n*i/N ) * 1if );
    };
    auto operator*( const vector &v ) const {
      T conv{0};
      int N = samples();
      for ( int i=0; i<N; i++ )
 	conv += at(i)*v.at(i); 
      float scale = N/2;
      return conv / scale;
    };
    void transform( vector &coefficients,bool naive=true ) const {
      using namespace std::complex_literals;
      auto N = coefficients.size();
      assert( this->size()==N );
      if (naive) {
	for (int frequency=1; frequency<=N; frequency++) {
	  T s{0};
	  for (int loc=0; loc<N; loc++) {
	    auto back_loc = N-loc;
	    s += signal[loc] * std::exp( static_cast<float>( pi*frequency*back_loc/N ) * 1if );
	  }
	  float scale = N/2;
	  s /= scale;
	  coefficients.at(frequency-1) = s;
	}
      } else {
      }
    };
    // diagnostics
    auto stringed() {
      stringstream s;
      for ( auto c : signal )
	s << setprecision(3) << c << " ";
      return s;
    };
  };
}

int main() {

#define N 32

  {
    fft::vector<std::complex<float>> sine(N),sine2(N);
    sine.set_wave();
    cout << "Sine: " << sine.stringed().str() << '\n';
    sine2.set_wave(2);
    auto ortho = sine*sine2;
    cout << "product 1x2: " << ortho << '\n';
    auto norm = sine2*sine2;
    cout << "product 2x2: " << norm << '\n';

    fft::vector<std::complex<float>> coefficients(N);
    sine.transform(coefficients);
    cout << "Sine transform: " << coefficients.stringed().str() << '\n';
    sine2.transform(coefficients);
    cout << "Sine2 transform: " << coefficients.stringed().str() << '\n';
  }

  return 0;
}
