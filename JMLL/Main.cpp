#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

#include "Main.h"
#include "src/tools/Tools.hpp"
#include "src/tools/Timer.hpp"
#include "src/backend/Matrix.hpp"
#include "src/nn/MLP.hpp"
#include "src/tools/CSVReader.hpp"

using namespace std;

void network();
int argmax(vec1d a);

int main()
{
    try {
        start_time();
        
        // INSERT CODE HERE //
        
        srand(int(time(0)));
        network();
        
        // END OF CODE //
        
        stop_time();
        cout << diff_time() << " ms\n";
        
    } catch (const char* msg) {
        cerr << msg << endl;
    }
    
    return 0;
}

void network()
{
    //// Data Parsing ////
    string xfilepath = "data/train_x.csv";
    string yfilepath = "data/train_y.csv";

    ifstream xfile (xfilepath);
    ifstream yfile (yfilepath);

    token2d xtext = readCSV(xfile);
    token2d ytext = readCSV(yfile);

    vec2d input_x = convert_to_double(xtext);
    vec2d targets = convert_to_double(ytext);
    //////////////////////
    
    //// Network Initialization ////
    int n_f = 2;
    int n_c = 2;
    vec_int nodes = {32, 16, 16};
    vec_string activations = {"linear", "relu", "relu", "sigmoid"};

    MLP my_network(n_f, n_c, nodes, activations);
    ////////////////////////////////
    
    //// Hyperparameters ////
    int n_epochs = 10;
    double lr = 0.1;
    string loss = "squared_error";
    /////////////////////////
    
    //// Training ////
    vec3d delta_w(my_network.get_weights().size(), vector<vector<double>>(my_network.get_weights()[0].size(), vector<double>(my_network.get_weights()[0][0].size(), 0.0)));
    
    int correct = 0;
    int total = 0;
    vec3d logits, outputs;
    vec1d predictions;
    int pos;
    int pos_t;
    for (int epoch = 0; epoch < n_epochs; epoch++)
    {
        for (int i = 0; i < input_x.size(); i++)
        {
            tie(logits, outputs) = my_network.forward_prop({input_x[i]});
//            my_network.SGD(logits, outputs, targets[i], loss, lr);
            
            predictions = outputs[outputs.size() -1][0];
            pos = argmax(predictions);
            pos_t = argmax(targets[i]);
            
//            cout << printmat({predictions});
//            cout << pos << ", " << pos_t << endl;
            
            if (pos == pos_t)
                correct++;
            total++;
        }
        
        cout << "Accuracy = " << to_string((double)correct / total) << endl;
        
    }
    //////////////////
}


int argmax(vec1d a)
{
    int position = 0;
    
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] > a[i-1])
        {
            position = i;
        }
    }
    
    return position;
}
