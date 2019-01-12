#include <iostream>
#include <vector>
#include "main.h"

#include <typeinfo>

//   Prints the given matrix   //
std::string printmat(std::vector<std::vector<double>> a)
{
    // Output string initialized
    std::string output = "";
    
    // Loop parameters
    int y, x;
    for (y = 0; y < a.size(); y++)  // a.size() number or rows
    {
        for (x = 0; x < a[0].size(); x++) // a[0].size() number of columns
        {
            std::string n = std::to_string(a[y][x]); // converts double value to string
            output += n + " "; // appends number and space to the return string
        }
        output += "\n"; // skip line after a row is finished being iterated
    }
    
    return output;
}

// Matrix Multiplication
std::vector<std::vector<double>> matmul(std::vector<std::vector<double>> a1, std::vector<std::vector<double>> a2)
{
    int row = (int) a1.size(); // number of rows in output matrix
    int col = (int) a2[0].size(); // number of columns in output matrix
    int ins = (int) a1[0].size(); // number of elements in columns of a1 and rows of a2
    
    // Return matrix
    std::vector<std::vector<double>> mat(row, std::vector<double>(col, 0.0));
    
    // Loop parameters
    double dot;
    int y, x, i;
    
    for (y = 0; y < row; y++)
    {
        for (x = 0; x < col; x++)
        {
            dot = 0; // Resets dot product for new entry in output matrix
            for (i = 0; i < ins; i++)
            {
                dot += a1[y][i] * a2[i][x];
            }
            mat[y][x] = dot;
        }
    }
    
    return mat;
};

// Matrix Transpose
std::vector<std::vector<double>> transpose(std::vector<std::vector<double>> a)
{
    int row = (int) a.size();
    int col = (int) a[0].size();
    
    std::vector<std::vector<double>> mat(col, std::vector<double>(row, 0.0));
    
    int y, x;
    for (y = 0; y < row; y++)
    {
        for (x = 0; x < col; x++)
        {
            mat[x][y] = a[y][x];
        }
    }
    
    return mat;
}
