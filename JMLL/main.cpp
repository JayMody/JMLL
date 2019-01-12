#include <iostream>
#include <vector>
#include <chrono>
#include "main.h"

int main()
{
    try {
        start_time();
        
        std::vector<std::vector<double>> a1 = {{1, 2, 3}, {4, 5, 6}};
        std::vector<std::vector<double>> a2 = transpose(a1);
        
        std::cout << "| a1 |\n" << printmat(a1) << std::endl;
        std::cout << "| a2 |\n" << printmat(a2) << std::endl;
        
        std::cout << "| a1 + a1 |\n" << printmat(add(a1, a1)) << std::endl;
        std::cout << "| a1 - a1 |\n" << printmat(subtract(a1, a1)) << std::endl;
        std::cout << "| a1 * a1 |\n" << printmat(multiply(a1, a1)) << std::endl;
        std::cout << "| a1 matmul a1 |\n" << printmat(matmul(a1, a2)) << std::endl;
        
        stop_time();
        std::cout << diff_time() << " ms\n";
        
    } catch (const char* msg) {
        std::cerr << msg << std::endl;
    }
    
    return 0;
}
