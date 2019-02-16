// Libraries
#include <cmath>

// Headers
#include "Loss.hpp"

//   Loss Functions   //
// Squared Error
double squared_error(double x, double l)
{
    return 1.0/2.0 * pow(l - x, 2);
}
double squared_error_prime(double x, double l)
{
    return x - l;
}

