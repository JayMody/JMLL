#include <iostream>
#include <vector>
#include <tuple>

#include "MLP.hpp"
#include "Activations.hpp"
#include "Loss.hpp"
#include "Matrix.hpp"

using namespace std;

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
MLP::MLP(int n_features, int n_classes, vec_int nodes, vec_string activations): n_features(n_features), n_classes(n_classes), nodes(nodes), activations(activations)
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
tuple<vec3d, vec3d> MLP::forward_prop(vec2d X)
{
    vec3d logits = {};
    vec3d outputs = {};
    
    logits.push_back(matmul(X, weights[0]));
    outputs.push_back(operate(logits[0], call_activation(activations[0])));

    int l;
    for (l = 1; l < weights.size(); l++)
    {
        logits.push_back(matmul(outputs[l-1], weights[l]));
        outputs.push_back(operate(logits[l], call_activation(activations[l])));
    }
    
    return {logits, outputs};
}

// Stochastic Gradient Descent //
vec3d MLP::SGD(vec3d logits, vec3d outputs, vec1d targets, string loss_func, double learning_rate)
{
    vec3d delta_w = {};
    
    vec1d error_loss;
    vec1d predictions = outputs[outputs.size() - 1][0];
    for (int i = 0; i < outputs[outputs.size() - 1].size(); i++)
    {
        error_loss.push_back(squared_error_prime(predictions[i], targets[i]));
    }

    vec2d error_term;
    int last = (int)weights.size() - 1;
    error_term = multiply({error_loss}, weights[last]);
    error_term = scale(error_term, learning_rate);
    error_term = multiply(error_term, logits[last]);
    delta_w.push_back(error_term);
    
//    vec2d error = subtract({targets}, outputs[outputs.size() - 1]);
//    vec2d error_term = multiply(weights[outpturs.size], )

    for (int l = (int)weights.size() - 2; l >= 0; l--)
    {
        error_loss = {};
        for (int i = 0; i < logits[logits.size() - 1].size(); i++)
        {
            error_loss.push_back(sigmoid_prime(logits[l][0][i]));
        }
        error_term = multiply({error_loss}, weights[l]);
        error_term = scale(error_term, learning_rate);
        error_term = multiply(error_term, logits[l]);
        delta_w.push_back(error_term);
    }

//    double delta_w;
//    double
//    for (int l = (int)weights.size(); l >= 0; l--)
//    {
//        for (int x = 0; x < weights[l].size(); x++)
//        {
//            for (int w = 0; w < weights[l][x].size(); w++)
//            {
//                delta_w = learning_rate *
//                weights[l][x][w]
//            }
//        }
//    }
    
    return delta_w;
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
