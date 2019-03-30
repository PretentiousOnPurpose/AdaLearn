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

void Sequential::fit(vector<float> x, vector<float> y, int epochs) {
    for (int e = 0; e < epochs; e++) {
        this->run(x);
        this->backProp(this->lr, this->loss_fn, y);
    }
}

void Sequential::backProp(float lr, string loss_fn, vector<float> y) {
    this->layers.back().backProp_L(lr, loss_fn, y);
    for (int i = this->layers.size() - 2; i >= 0; i--) {
        this->layers[i].backProp_L(lr, loss_fn, this->layers[i+1].dErr);
    }
}
