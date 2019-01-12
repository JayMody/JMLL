#include <iostream>
#include <vector>
#include <chrono>
#include "main.h"

int main()
{
    start_time();
    
    std::vector<std::vector<double>> a1 = {{1, 2, 3}, {4, 5, 6}};
    std::vector<std::vector<double>> a2 = {{1, 2}, {3, 4}, {5, 6}};

    std::cout << printmat(a1) << std::endl;
    std::cout << printmat(a2) << std::endl;
    
    std::vector<std::vector<double>> n = matmul(a1, a2);
    std::cout << printmat(n) << std::endl;
    
    stop_time();
    std::cout << diff_time() << " ms\n";
    
    return 0;
}
