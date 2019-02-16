#include <vector>
#include <string>
#include <istream>

#include "Matrix.hpp"

#ifndef CSVReader_hpp
#define CSVReader_hpp

// Type Defintitions
typedef std::vector<std::string> token1d;
typedef std::vector<std::vector<std::string>> token2d;

// Functions
token1d readRow(std::string &row);
token2d readCSV(std::ifstream &in);

vec2d convert_to_double(token2d text);

#endif /* CSVReader_hpp */
