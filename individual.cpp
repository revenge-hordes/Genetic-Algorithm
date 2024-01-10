#include "individual.h"
#include <cmath>

double fitnessFunction(double x) {
    return sin(x) + 2 * cos(2 * x);
}

Individual::Individual() {
    x = static_cast<double>(rand()) / RAND_MAX * 10.0 - 5.0;  // Random initialization between -5 and 5
    fitness = fitnessFunction(x);
}
