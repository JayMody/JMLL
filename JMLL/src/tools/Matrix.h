//
//  Matrix.h
//  JMLL
//
//  Created by Jay Mody on 2019-01-15.
//  Copyright © 2019 Jay Mody. All rights reserved.
//

#include <vector>
#include <string>

#include "Tools.h"

#ifndef Matrix_h
#define Matrix_h

// Basics
std::string printmat(std::vector<std::vector<double>> a);

// Arithemetic
std::vector<std::vector<double>> matmul(std::vector<std::vector<double>> a1, std::vector<std::vector<double>> a2);
std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> a);

// Initializers
std::vector<std::vector<double>> random_normal(int rows, int columns);

// Function Operator
std::vector<std::vector<double>> operate(std::vector<std::vector<double>> a, activation_function f);

// Elementary Ops
std::vector<std::vector<double>> multiply(std::vector<std::vector<double>> a1, std::vector<std::vector<double>> a2);
std::vector<std::vector<double>> add(std::vector<std::vector<double>> a1, std::vector<std::vector<double>> a2);
std::vector<std::vector<double>> subtract(std::vector<std::vector<double>> a1, std::vector<std::vector<double>> a2);

#endif /* Matrix_h */
