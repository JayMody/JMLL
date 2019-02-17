#include <vector>
#include <string>
#include <istream>

#include "Matrix.hpp"

using namespace std;

#ifndef CSVReader_hpp
#define CSVReader_hpp

// Type Defintitions
typedef vector<string> token1d;
typedef vector<vector<string>> token2d;

// Functions
token1d readRow(string &row);
token2d readCSV(ifstream &in);

vec2d convert_to_double(token2d text);

#endif /* CSVReader_hpp */
