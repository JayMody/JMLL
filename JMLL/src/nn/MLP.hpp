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

#ifndef MLP_h
#define MLP_h

class MLP {
public:
    //   Constructors   //
    // Default Constructor
    MLP();
    
    // Overload Constructor
    MLP(int i_features, int i_classes, std::string loss_func, vec_int i_nodes, vec_string i_activations);
    
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
    vec2d forward_prop(vec2d X);
    void SGD(vec1d predictions, vec1d targets);
    
private:
    // Member Variables
    int n_features;
    int n_layers;
    int n_classes;
    
    std::string loss_func;
    
    vec_int nodes;
    vec_string activations;
    
    vec3d weights;
};

#endif
