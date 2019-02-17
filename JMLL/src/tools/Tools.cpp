// Libraries
#include <cstdlib>

// Headesr
#include "Tools.hpp"

using namespace std;

//   Tools   //
double random(double a, double b)
{
    double r = ((double) rand() / (RAND_MAX));
    r *= b - a;
    r += a;
    
    return r;
}
