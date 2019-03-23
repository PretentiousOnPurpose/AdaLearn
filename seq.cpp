#include <iostream>
#include "seq.hpp"
#include <string>

#include <vector>

using std::vector;
using namespace std;

void Sequential::Add(int units, string act_fn, int input_dims) {
    auto L = Layer(units, act_fn);
    if (input_dims) {
        Sequential::dims.push_back(input_dims);
        L.initWeights(input_dims);
    } else {
        L.initWeights(Sequential::dims.back());
    }
    
    Sequential::dims.push_back(units);
    Sequential::layers.push_back(L);
}

void Sequential::Run(vector<float> x) {
    this->layers[0].activation(x);
    
    for (int i = 1; i < this->layers.size(); i++) {
        this->layers[i].activation(this->layers[i - 1].l_y_hat);
    }

    this->y_hat = this->layers.back().l_y_hat;
}