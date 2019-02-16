// Libraries
#include <cmath>
#include <string>

// Headers
#include "Activations.hpp"

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

////// Activation Functions ///////
// Linear
double linear(double x)
{
    return x;
}
double linear_prime(double x)
{
    return 1;
}

// Sigmoid
double sigmoid(double x)
{
    return 1.0 / (1.0 + pow(M_E, -1.0 * x));
}
double sigmoid_prime(double x)
{
    return sigmoid(x) * (1.0 - sigmoid(x));
}

// Relu
double relu(double x)
{
    if (x < 0)
        return 0;
    return x;
}
double relu_prime(double x)
{
    if (x < 0)
        return 0;
    return 1;
}

// General Operators
vec2d operate(vec2d a, activation_function f)
{
    int row = (int) a.size();
    int col = (int) a[0].size();
    
    int y, x;
    for (y = 0; y < row; y++)
    {
        for (x = 0; x < col; x++)
        {
            a[y][x] = (*f)(a[y][x]);
        }
    }
    
    return a;
}
