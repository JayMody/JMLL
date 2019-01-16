#include <iostream>
#include <vector>
#include <chrono>

#include "Main.h"
#include "tools/Tools.h"
#include "tools/Timer.h"
#include "tools/Matrix.h"
#include "nn/MLP.h"

int main()
{
    try {
        start_time();
        
        int n_f = 20;
        int n_c = 3;
        std::vector<int> nodes = {64, 64};
        std::vector<std::string> activations = {"sigmoid", "sigmoid", "sigmoid"};
        
        MLP my_network(n_f, n_c, nodes, activations);
        
        std::vector<std::vector<std::vector<double>>> a = my_network.get_weights();
        std::vector<double> input_x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
        
//        std::cout << input_x.size() << std::endl;
//        std::cout << {input_x}[0].size() << std::endl << std::endl;
        
        for (int i = 0; i < a.size(); i++)
        {
//            std::cout << a[i].size() << std::endl;
//            std::cout << a[i][0].size() << std::endl << std::endl;
//            std::cout << printmat(a[i]) << std::endl << std::endl;
        }
        
        std::vector<std::vector<double>> output = my_network.forward_prop(input_x);
        
        std::cout << printmat(output) << std::endl;
//        std::cout << output.size() << std::endl;
//        std::cout << output[0].size() << std::endl;
//        std::cout << printmat(output) << std::endl << std::endl;

        
        
//        std::cout << a[0][0] << std::endl;
//        std::cout << a[0][1] << std::endl;
//        std::cout << a[1][0] << std::endl;
//        std::cout << a[1][1] << std::endl;
//        std::cout << a[1][2] << std::endl;
        
//        std::vector<std::vector<double>> a1 = {{1, 0}, {2, -2}, {2, -4}};
//        std::vector<std::vector<double>> a2 = {{1, 0, -4, 3}, {-1, 3, 1, 1}};
//
//        std::cout << "| a1 |\n" << printmat(a1) << std::endl;
//        std::cout << "| a2 |\n" << printmat(a2) << std::endl;
//
//        std::cout << "| a1 + a1 |\n" << printmat(add(a1, a1)) << std::endl;
//        std::cout << "| a1 - a1 |\n" << printmat(subtract(a1, a1)) << std::endl;
//        std::cout << "| a1 * a1 |\n" << printmat(multiply(a1, a1)) << std::endl;
//        std::cout << "| a1 matmul a1 |\n" << printmat(matmul(a1, a2)) << std::endl;
        
//        for (int i = 0; i < 100; i++)
//        {
//            std::cout << random_normal(-1, 1) << std::endl;
//        }
        
        stop_time();
        std::cout << diff_time() << " ms\n";
        
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
    
    return 0;
}
