// Headers
#include "Matrix.hpp"

using namespace std;

////// Header //////
#ifndef Activations_hpp
#define Activations_hpp

// Type Definitions
typedef double (*activation_function)(double);

// Activation Functions
activation_function call_activation(string);

double linear(double x);
double linear_prime(double x);

double sigmoid(double x);
double sigmoid_prime(double x);

double relu(double x);
double relu_prime(double x);

// Activation functions list
const vec_string act_names = {"linear", "sigmoid", "relu"};
const vector<activation_function> act_functions = {&linear, &sigmoid, &relu};

// Activation Function Operator
vec2d operate(vec2d a, activation_function f);

#endif /* Activations_hpp */
