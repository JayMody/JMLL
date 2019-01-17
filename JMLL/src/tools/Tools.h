// J-Machine Learning Library
// Author: Jay Mody
//
// Tools.cpp
// Description:
//
//
//

#ifndef Tools_h
#define Tools_h

// Tools
double random(double a, double b);

// Activation Functions
double linear(double x);
double sigmoid(double x);
double relu(double x);

// Loss Functions
double squared_error(double x, double l);

#endif /* Tools_h */
