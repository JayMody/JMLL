#include <iostream>
#include <vector>

#include "MLP.hpp"
#include "Activations.hpp"
#include "Loss.hpp"
#include "Matrix.hpp"

// Defualt Constructor
MLP::MLP()
{
    // Member Variables
    n_features = 0;
    n_layers = 0;
    n_classes = 0;
    
    loss_func = "";
    
    nodes = {};
    activations = {};
    
    weights = {{{}}};
}

// Overload Constructor
MLP::MLP(int n_features, int n_classes, std::string loss_func, vec_int nodes, vec_string activations): n_features(n_features), n_classes(n_classes), loss_func(loss_func), nodes(nodes), activations(activations)
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
vec2d MLP::forward_prop(vec2d features)
{
    std::vector<std::vector<double>> X = features;

    std::vector<std::vector<double>> logits = matmul(X, weights[0]);
    logits = operate(logits, call_activation(activations[0]));
    
//    std::cout << "Weight  " << std::to_string(0) << std::endl;
//    std::cout << weights[0].size() << std::endl;
//    std::cout << weights[0][0].size() << std::endl << std::endl;

    int l;
    for (l = 1; l < weights.size(); l++)
    {
//        std::cout << logits.size() << std::endl;
//        std::cout << logits[0].size() << std::endl << std::endl;
        logits = matmul(logits, weights[l]);
        logits = operate(logits, call_activation(activations[l]));

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
vec_int MLP::get_nodes(){
    return nodes;
}
vec_string MLP::get_activations(){
    return activations;
}
vec3d MLP::get_weights(){
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
void MLP::set_nodes(vec_int inodes){
    nodes = inodes;
}
void MLP::set_activations(vec_string iactivations){
    activations = iactivations;
}
void MLP::set_weights(vec3d iweights){
    weights = iweights;
}
