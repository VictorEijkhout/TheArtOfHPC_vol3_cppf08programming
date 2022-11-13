#include <cmath>

#include "constperf.h"

double c::f() const {
  return sin(cos(tan(exp(5.))));
}
