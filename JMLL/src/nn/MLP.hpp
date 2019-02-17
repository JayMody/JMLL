// J-Machine Learning Library
// Author: Jay Mody
//
// MLP.h
// Description:
//
//
//

#include <iostream>
#include <string>
#include <vector>

#include "Matrix.hpp"

using namespace std;

#ifndef MLP_h
#define MLP_h

class MLP {
public:
    //   Constructors   //
    // Default Constructor
    MLP();
    
    // Overload Constructor
    MLP(int i_features, int i_classes, vec_int i_nodes, vec_string i_activations);
    
    // Destructor
    ~MLP();
    
    
    //   Accessor Functions   //
    int get_n_features();
    int get_n_layers();
    int get_n_classes();
    
    vec_int get_nodes();
    vec_string get_activations();
    
    vec3d get_weights();
    
    
    //   Mutator Functions   //
    void set_n_features(int n_features);
    void set_n_layers(int n_layers);
    void set_n_classes(int n_classes);
    
    void set_nodes(vec_int nodes);
    void set_activations(vec_string activations);
    
    void set_weights(vec3d weights);
    
    //   MLP Functions    //
    tuple<vec3d, vec3d> forward_prop(vec2d X);
    vec3d SGD(vec3d logits, vec3d outputs, vec1d targets, string loss_func, double learning_rate);
    
private:
    // Member Variables
    int n_features;
    int n_layers;
    int n_classes;
    
    string loss_func;
    
    vec_int nodes;
    vec_string activations;
    
    vec3d weights;
};

#endif
