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

#ifndef Matrix_h
#define Matrix_h

// Type Definitions
typedef std::vector<int> vec_int;
typedef std::vector<std::string> vec_string;

typedef std::vector<double> vec1d;
typedef std::vector<std::vector<double>> vec2d;
typedef std::vector<std::vector<std::vector<double>>> vec3d;

// Basics
std::string printmat(vec2d a);

// Arithemetic
vec2d matmul(vec2d a1, vec2d a2);
vec2d transpose(vec2d a);

// Initializers
vec2d random_normal(int rows, int columns, double lowerbound = -1.0, double upperbound = 1.0);

// Elementary Ops
vec2d multiply(vec2d a1, vec2d a2);
vec2d add(vec2d a1, vec2d a2);
vec2d subtract(vec2d a1, vec2d a2);

#endif /* Matrix_h */
