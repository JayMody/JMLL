# J-Machine Learning Library

**Author: Jay Mody**

This project is a WIP ml library for multilayer perceptron networks in c++. This library for proof of concept and practice rather than implementation for actual programs. 

Matrices are stored as 2d std::vector objects. Matrix multiplication, printing, tranposes and all other operations were coded new.


## To Do
- find/create simple training data for classification
- neural-network class
- bias terms
- forward propogation
- loss
- optimization (back propogation gradient descent)


## Functionality
### Matrix Operations

**Input a1**

1 2 3

4 5 6


**Input a2**

1 2

3 4

5 6


**Matmul algorithim**

```c++
std::vector<std::vector<double>> matmul(std::vector<std::vector<double>> a1, std::vector<std::vector<double>> a2)
{
    int row = a1.size(); // number of rows in output matrix
    int col = a2[0].size(); // number of columns in output matrix
    int ins = a1[0].size(); // number of elements in columns of a1 and rows of a2
    
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
```


**Output**

22 28

39 64