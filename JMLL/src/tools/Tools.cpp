// J-Machine Learning Library
// Author: Jay Mody
//
// Tools.cpp
// Description:
//
//
//

#include <cmath>
#include <cstdlib>

#include "Tools.h"

//   Tools   //
double random(double a, double b)
{
    double r = ((double) rand() / (RAND_MAX));
    r *= b - a;
    r += a;
    
    return r;
}

//   Activation Functions   //
double sigmoid(double x)
{
    return 1 / (1 + pow(M_E, -1 * x));
}
double relu(double x)
{
    if (x < 0)
    {
        return 0;
    }
    return x;
}
