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
#include <string>

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
activation_function call_activation(std::string activation)
{
    for (int i = 0; i < act_names.size(); i++)
    {
        if (activation == act_names[i])
            return act_functions[i];
    }
    
    return act_functions[0];
}

double linear(double x)
{
    return x;
}
double sigmoid(double x)
{
    return 1.0 / (1.0 + pow(M_E, -1.0 * x));
}
double relu(double x)
{
    if (x < 0)
    {
        return 0;
    }
    return x;
}

//   Loss Functions   //
double squared_error(double x, double l)
{
    return pow(l - x, 2);
}
