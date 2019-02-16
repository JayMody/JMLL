#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

#include "Main.h"
#include "src/tools/Tools.hpp"
#include "src/tools/Timer.hpp"
#include "src/backend/Matrix.hpp"
#include "src/nn/MLP.hpp"
#include "src/tools/CSVReader.hpp"

void network();
void matrix_multiplication();

int main()
{
    try {
        start_time();
        
        // INSERT CODE HERE //
        
        network();
        
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
//    token2d p = {{"1", "2"}, {"3", "4"}};
//    std::cout << printmat(convert_to_double(p)) << std::endl;
    
    //// FILES ////
    std::string xfilepath = "data/train_x.csv";
    std::string yfilepath = "data/train_y.csv";

    std::ifstream xfile (xfilepath);
    std::ifstream yfile (yfilepath);

    token2d xtext = readCSV(xfile);
    token2d ytext = readCSV(yfile);

    vec2d input_x = convert_to_double(xtext);
    vec2d targets = convert_to_double(ytext);
    ///////////////
    
    vec2d inp = {input_x[0]};
    
    int n_f = 2;
    int n_c = 2;
    std::vector<int> nodes = {16, 16};
    std::vector<std::string> activations = {"sigmoid", "sigmoid", "sigmoid"};

    MLP my_network(n_f, n_c, "squared_error", nodes, activations);

    std::vector<std::vector<std::vector<double>>> a = my_network.get_weights();
//    std::vector<std::vector<double>> input_x = random_normal(1, n_f);
    std::vector<std::vector<double>> output = my_network.forward_prop(inp);
    
    std::cout << printmat(output) << std::endl;
}



void readFrom()
{
    
}
