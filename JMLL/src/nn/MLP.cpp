#include <iostream>
#include <vector>

#include "MLP.h"
#include "Matrix.h"
#include "Tools.h"

// Defualt Constructor
MLP::MLP()
{
    // Member Variables
    n_features = 0;
    n_layers = 0;
    n_classes = 0;
    
    nodes = {};
    activations = {};
    
    weights = {{{}}};
}

// Overload Constructor
MLP::MLP(int n_features, int n_classes, std::vector<int> nodes, std::vector<std::string> activations): n_features(n_features), n_classes(n_classes), nodes(nodes), activations(activations)
{
    n_layers = (int) nodes.size();
    
    weights.push_back(random_normal(n_features, nodes[0]));
    
    int l = 0;
    int a = nodes[0];
    for (l = 1; l < (n_layers); l++)
    {
        weights.push_back(random_normal(a, nodes[l]));
        a = nodes[l];
    }
    
    weights.push_back(random_normal((int)weights.back()[0].size(), n_classes));
}

// Destructor
MLP::~MLP()
{
    
}

//   MLP Functions   //
// Forward Propogation
std::vector<std::vector<double>> MLP::forward_prop(std::vector<std::vector<double>> features)
{
    std::vector<std::vector<double>> X = features;

    std::vector<std::vector<double>> logits = matmul(X, weights[0]);
    logits = operate_bad(logits, activations[0]);

//    std::cout << "Weight  " << std::to_string(0) << std::endl;
//    std::cout << weights[0].size() << std::endl;
//    std::cout << weights[0][0].size() << std::endl << std::endl;

    int l;
    for (l = 1; l < weights.size(); l++)
    {
//        std::cout << logits.size() << std::endl;
//        std::cout << logits[0].size() << std::endl << std::endl;
        logits = matmul(logits, weights[l]);
        logits = operate_bad(logits, activations[l]);

//        std::cout << "Weight  " << std::to_string(l) << std::endl;
//        std::cout << weights[l].size() << std::endl;
//        std::cout << weights[l][0].size() << std::endl << std::endl;
    }

//    std::cout << logits.size() << std::endl;
//    std::cout << logits[0].size() << std::endl << std::endl;
//
//    std::vector<double> output = transpose(logits)[0];

    return logits;
}


// Activation Function
//std::function<double()> MLP::activation_function(std::string activation)
//{
//    if (activation == "sigmoid")
//    {
//        double (*p_sigmoid)(double);
//        p_sigmoid = &sigmoid;
//        
//        return sigmoid;
//    }
//    else if (activation == "relu")
//    {
//        double (*p_relu)(double);
//        p_relu = &relu;
//        
//        return relu;
//    }
//    
//    double (*p_linear)(double);
//    p_linear = &linear;
//    
//    return linear;
//}


//   Accessor Functions   //
int MLP::get_n_features(){
    return n_features;
}
int MLP::get_n_layers(){
    return n_layers;
}
int MLP::get_n_classes(){
    return n_classes;
}
std::vector<int> MLP::get_nodes(){
    return nodes;
}
std::vector<std::string> MLP::get_activations(){
    return activations;
}
std::vector<std::vector<std::vector<double>>> MLP::get_weights(){
    return weights;
}


//   Mutators   //
void MLP::set_n_features(int in_features){
    n_features = in_features;
}
void MLP::set_n_layers(int in_layers){
    n_layers = in_layers;
}
void MLP::set_n_classes(int in_classes){
    n_classes = in_classes;
}
void MLP::set_nodes(std::vector<int> inodes){
    nodes = inodes;
}
void MLP::set_activations(std::vector<std::string> iactivations){
    activations = iactivations;
}
void MLP::set_weights(std::vector<std::vector<std::vector<double>>> iweights){
    weights = iweights;
}
