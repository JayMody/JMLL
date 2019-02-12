#include <iostream>
#include <vector>
#include <chrono>

#include "Main.h"
#include "src/tools/Tools.h"
#include "src/tools/Timer.h"
#include "src/tools/Matrix.h"
#include "src/nn/MLP.h"

void network();
void matrix_multiplication();


int main()
{
    try {
        start_time();
        
        // INSERT CODE HERE //
        
        matrix_multiplication();
        
        // END OF CODE //
        
        stop_time();
        std::cout << diff_time() << " ms\n";
        
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
    
    return 0;
}

void matrix_multiplication()
{
    std::vector<std::vector<double>> a = {
        {27,    7,    41,    -40},
        {15,    49,    13,    23},
        {3,    46,    24,    15},
        {21,    -14,    -20,    -32},
        {-49,    -27,    -42,    42}
    };
    std::vector<std::vector<double>> b = {
        {-9,    7,    40,    -7},
        {-30,    -41,    -20,    -20}
    };
    std::vector<std::vector<double>> c = {
        {4,    4},
        {31,    -23},
        {-33,    -24},
        {20,    -24},
        {10,    45}
    };
    
    std::cout << "| AtCB |\n" << printmat(matmul(matmul(transpose(a), c), b)) << std::endl;
    
    std::cout << "| A) |\n" << printmat(matmul(matmul(c, b), transpose(a))) << std::endl;
    
    std::cout << "| B) |\n" << printmat(matmul(matmul(a, transpose(b)), transpose(c))) << std::endl;
    
    std::cout << "| C) |\n" << printmat(matmul(matmul(transpose(a), c), b)) << std::endl;
    
    int m = 2436 + 90694 + 28194 - 40876 + 98745;
    
    std::cout << m << std::endl;
    
}

void network()
{
    int n_f = 32;
    int n_c = 10;
    std::vector<int> nodes = {16, 16};
    std::vector<std::string> activations = {"sigmoid", "sigmoid", "sigmoid"};

    MLP my_network(n_f, n_c, nodes, activations);

    std::vector<std::vector<std::vector<double>>> a = my_network.get_weights();
    std::vector<std::vector<double>> input_x = random_normal(1, n_f);
    std::vector<std::vector<double>> output = my_network.forward_prop(input_x);
    
    std::cout << printmat(output) << std::endl;
}



void readFrom()
{
    
}
