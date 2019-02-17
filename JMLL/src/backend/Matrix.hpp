//
//  Matrix.h
//  JMLL
//
//  Created by Jay Mody on 2019-01-15.
//  Copyright © 2019 Jay Mody. All rights reserved.
//

#include <vector>
#include <string>

#include "Tools.hpp"

using namespace std;

#ifndef Matrix_h
#define Matrix_h

// Type Definitions
typedef vector<int> vec_int;
typedef vector<string> vec_string;

typedef vector<double> vec1d;
typedef vector<vector<double>> vec2d;
typedef vector<vector<vector<double>>> vec3d;

// Basics
string printmat(vec2d a);

// Arithemetic
vec2d matmul(vec2d a1, vec2d a2);
vec2d transpose(vec2d a);

// Initializers
vec2d random_normal(int rows, int columns, double lowerbound = -1.0, double upperbound = 1.0);

// Elementary Ops
vec2d multiply(vec2d a1, vec2d a2);
vec2d add(vec2d a1, vec2d a2);
vec2d subtract(vec2d a1, vec2d a2);

vec2d bump(vec2d a, double x);
vec2d scale(vec2d a, double x);

string get_shape(vec2d mat);

#endif /* Matrix_h */
