#include <iostream>
#include <vector>
#include <chrono>

#include "Main.h"
#include "tools/Tools.h"
#include "tools/Timer.h"
#include "tools/Matrix.h"
#include "nn/MLP.h"

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
    std::vector<std::vector<double>> a1 = {{1, 0, -3, 3}, {-1, 3, 1, -1}};
    std::vector<std::vector<double>> a2 = {{1, 0, 3}, {4, 4, -1}, {2, 3, 1}};
    std::vector<std::vector<double>> c = {{1, 0}, {3, -2}, {2, -2}};
    
    std::cout << "| a1 |\n" << printmat(a1) << std::endl;
    std::cout << "| a2 |\n" << printmat(a2) << std::endl;
    
    std::cout << "| a1 + a1 |\n" << printmat(add(a1, a1)) << std::endl;
    std::cout << "| a1 - a1 |\n" << printmat(subtract(a1, a1)) << std::endl;
    std::cout << "| a1 * a1 |\n" << printmat(multiply(a1, a1)) << std::endl;
    std::cout << "| a1 matmul a1 |\n" << printmat(matmul(a1, a2)) << std::endl;
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
