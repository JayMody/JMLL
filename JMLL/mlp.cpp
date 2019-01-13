#include <iostream>
#include <cmath>
#include <vector>

class mlp
{
    int num_features;
    int num_layers;
    std::vector<int> num_nodes;
    std::vector<std::string> activation;
    int num_classes;
    std::vector<std::vector<std::vector<double>>> weights;
    
};

//   Create NN   //
//void nn(int num_features, int num_classes, std::vector<int> num_nodes, std::vector<std::string> activation)
//{
//    num_layers = num_nodes.size();
//
//    int l, y, x;
//    for (l = 0; l < num_layers; l++)
//    {
//        for (y = 0; y < num_nodes[l]; y++)
//        std::vector<std::vector<double>>
//        weights[l] =
//    }
//}
//
////   Forward Propogation   //
//std::vector<double> forward_prop(std::vector<double> x)
//{
//    std::vector<double> logits;
//
//    int l;
//    for (l = 0; l < num_layers; l++)
//    {
//        weights[]
//    }
//
//    return 0;
//}

//   Activation Functions   //
double sigmoid(double x)
{
    return 1 / (1 + pow(M_E, -1 * x));
}
double relu(double x)
{
    if (x < 0)
    {
        return 0;
    }
    
    return x;
}
