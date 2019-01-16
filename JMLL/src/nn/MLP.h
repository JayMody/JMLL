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

#ifndef MLP_h
#define MLP_h

class MLP {
public:
    //   Constructors   //
    // Default Constructor
    MLP();
    
    // Overload Constructor
    MLP(int i_features, int i_classes, std::vector<int> i_nodes, std::vector<std::string> i_activations);
    
    // Destructor
    ~MLP();
    
    
    //   Accessor Functions   //
    int get_n_features();
    int get_n_layers();
    int get_n_classes();
    
    std::vector<int> get_nodes();
    std::vector<std::string> get_activations();
    
    std::vector<std::vector<std::vector<double>>> get_weights();
    
    
    //   Mutator Functions   //
    void set_n_features(int n_features);
    void set_n_layers(int n_layers);
    void set_n_classes(int n_classes);
    
    void set_nodes(std::vector<int> nodes);
    void set_activations(std::vector<std::string> activations);
    
    void set_weights(std::vector<std::vector<std::vector<double>>> weights);
    
    //   MLP Functions    //
    std::vector<std::vector<double>> forward_prop(std::vector<double> X);
    
private:
    // Member Variables
    int n_features;
    int n_layers;
    int n_classes;
    
    std::vector<int> nodes;
    std::vector<std::string> activations;
    
    std::vector<std::vector<std::vector<double>>> weights;
};

#endif
