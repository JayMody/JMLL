// J-Machine Learning Library
// Author: Jay Mody
//
// Tools.cpp
// Description:
//
//
//

#include <string>
#include <vector>

#ifndef Tools_h
#define Tools_h

// Type Definitions
typedef double (*activation_function)(double);

// Tools
double random(double a, double b);

// Activation Functions
activation_function call_activation(std::string);

double linear(double x);
double sigmoid(double x);
double relu(double x);

// Activation functions list
const std::vector<std::string> act_names = {"linear", "sigmoid", "relu"};
const std::vector<activation_function> act_functions = {&linear, &sigmoid, &relu};

// Loss Functions
double squared_error(double x, double l);

#endif /* Tools_h */
