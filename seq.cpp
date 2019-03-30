#include <iostream>
#include "seq.hpp"
#include <string>

#include <vector>

using std::vector;
using namespace std;

void Sequential::add(int units, string act_fn, int input_dims) {
    auto L = Layer(units, act_fn, "");
    if (input_dims) {
        Sequential::dims.push_back(input_dims);
        L.initWeights(input_dims);
        L.type = "input";
    } else {
        Sequential::layers.back().type = "hidden";
        L.initWeights(Sequential::dims.back());
        L.type = "output";
    }

    Sequential::dims.push_back(units);
    Sequential::layers.push_back(L);
}

void Sequential::run(vector<float> x) {
    this->layers[0].activation(x);

    for (int i = 1; i < this->layers.size(); i++) {
        this->layers[i].activation(this->layers[i - 1].l_y_hat);
    }

    this->y_hat = this->layers.back().l_y_hat;
}

void Sequential::compile(float lr, string loss_fn) {
    this->lr = lr;
    this->loss_fn = loss_fn;
}

void Sequential::backProp(vector<float> x, vector<float> y) {
    if (this->loss_fn == "mean_squared_error") {
        
    } else if (this->loss_fn == "binary_cross_entropy") {

    }
}
