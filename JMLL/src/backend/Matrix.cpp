// Libraries
#include <iostream>
#include <vector>

// Headers
#include "Matrix.hpp"
#include "Tools.hpp"

using namespace std;

// Print Matrix
/**
 * Returns a string representation of a matrix
 *
 * @param mat The input matrix
 * @return String representation of mat
 */
string printmat(vec2d mat)
{
    // Output string initialized
    string output = "";
    
    // Loop parameters
    int y, x;
    for (y = 0; y < mat.size(); y++)  // a.size() number or rows
    {
        for (x = 0; x < mat[0].size(); x++) // a[0].size() number of columns
        {
            string n = to_string(mat[y][x]); // converts double value to string
            output += n + ", "; // appends number and space to the return string
        }
        output += "\n"; // skip line after a row is finished being iterated
    }
    
    return output;
}

// Matrix Multiplication
/**
 * Perform matrix multiplication between two matrices (mat1 * mat2) and returns the resulting matrix. The input matrices must be compatible, that is mat1 and mat2 are of shape (a * b) and (b * c).
 *
 * @param mat1 The first matrix.
 * @param mat2 The second matrix
 * @return String representation of mat
 */
vec2d matmul(vec2d mat1, vec2d mat2)
{
    int ins;
    if (mat1[0].size() != mat2.size())
    {
        throw "Error: Matrices shapes incompatible for matmul";
    }
    else
    {
        ins = (int) mat1[0].size(); // number of elements in columns of a1 and rows of a2
    }
    
    int row = (int) mat1.size(); // number of rows in output matrix
    int col = (int) mat2[0].size(); // number of columns in output matrix
    
    // Return matrix
    vec2d product_mat(row, vector<double>(col, 0.0));
    
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
                dot += mat1[y][i] * mat2[i][x];
            }
            product_mat[y][x] = dot;
        }
    }
    
    return product_mat;
};

// Matrix Transpose
/**
 * Returns the input matrix transposed
 *
 * @param mat The input matrix.
 * @return Transposed matrix
 */
vec2d transpose(vec2d mat)
{
    int row = (int) mat.size();
    int col = (int) mat[0].size();
    
    vec2d transposed_mat(col, vector<double>(row, 0.0));
    
    int y, x;
    for (y = 0; y < row; y++)
    {
        for (x = 0; x < col; x++)
        {
            transposed_mat[x][y] = mat[y][x];
        }
    }
    
    return transposed_mat;
}

// Initializers
/**
 * Generates a matrix with a random normal distribution
 *
 * @param rows Number of rows
 * @param columns Number of columns
 * @param lowerbound Lower bound of the distribution
 * @param upperbound Upper bound of the distribution
 *
 * @return Matrix of shape (rows * columns) with random normal distribution
 */
vec2d random_normal(int rows, int columns, double lowerbound, double upperbound)
{
    vec2d mat(rows, vector<double>(columns, 0.0));
    
    int y, x;
    for (y = 0; y < rows; y++)
    {
        for (x = 0; x < columns; x++)
        {
            mat[y][x] = random(lowerbound, upperbound);
        }
    }
    
    return mat;
}

// Matrix Operations
vec2d add(vec2d a1, vec2d a2)
{
    int row, col;
    if (a1.size() != a2.size() || a1[0].size() != a2[0].size())
    {
        throw "Error: Matrices shapes incompatible for elementary operations";
    }
    else
    {
        row = (int) a1.size();
        col = (int) a1[0].size();
    }
    vec2d mat(row, vector<double>(col, 0.0));
    
    int y, x;
    for (y = 0; y < row; y++)
    {
        for (x = 0; x < col; x++)
        {
            mat[y][x] = a1[y][x] + a2[y][x];
        }
    }
    
    return mat;
}
vec2d subtract(vec2d a1, vec2d a2)
{
    int row, col;
    if (a1.size() != a2.size() || a1[0].size() != a2[0].size())
    {
        throw "Error: Matrices shapes incompatible for elementary operations";
    }
    else
    {
        row = (int) a1.size();
        col = (int) a1[0].size();
    }
    vec2d mat(row, vector<double>(col, 0.0));
    
    int y, x;
    for (y = 0; y < row; y++)
    {
        for (x = 0; x < col; x++)
        {
            mat[y][x] = a1[y][x] - a2[y][x];
        }
    }
    
    return mat;
}
vec2d multiply(vec2d a1, vec2d a2)
{
    int row, col;
    if (a1.size() != a2.size() || a1[0].size() != a2[0].size())
    {
        throw "Error: Matrices shapes incompatible for elementary operations";
    }
    else
    {
        row = (int) a1.size();
        col = (int) a1[0].size();
    }
    vec2d mat(row, vector<double>(col, 0.0));
    
    int y, x;
    for (y = 0; y < row; y++)
    {
        for (x = 0; x < col; x++)
        {
            mat[y][x] = a1[y][x] * a2[y][x];
        }
    }
    
    return mat;
}

vec2d bump(vec2d a, double n)
{
    int row, col;
    row = (int) a.size();
    col = (int) a[0].size();
    
    int y, x;
    for (y = 0; y < row; y++)
    {
        for (x = 0; x < col; x++)
        {
            a[y][x] += n;
        }
    }
    
    return a;
}
vec2d scale(vec2d a, double n)
{
    int row, col;
    row = (int) a.size();
    col = (int) a[0].size();
    
    int y, x;
    for (y = 0; y < row; y++)
    {
        for (x = 0; x < col; x++)
        {
            a[y][x] *= n;
        }
    }
    
    return a;
}

string get_shape(vec2d mat)
{
    return "{" + to_string(mat.size()) + ", " + to_string(mat[0].size()) + "}";
}
