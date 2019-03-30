#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <random>
#include "layers.hpp"
#include "utils.hpp"

using std::vector;
using namespace std;

Layer::Layer(int units, string act_fn, string type) {
    this->units = units;
    this->act_fn = act_fn;
    this->type = type;
}

void Layer::initWeights(int input_dims) {
    for (int i = 0; i < this->units; i++) {
        vector<float> tmp;
        for (int i = 0; i < input_dims; i++) {
            tmp.push_back(rand() / double(RAND_MAX));
        }
        this->weights.push_back(tmp);
    }
}

void Layer::activation(vector<float> x) {

    this->input = x;
    vector<float> y = matMul(this->weights, x);

    if (this->act_fn == "relu") {
        y = relu(y);
    } else {
        y = sigmoid(y);
    }

    this->l_y_hat = y;
}


vector<float> Layer::relu(vector<float> x) {
    vector<float> y;

    for (float i : x) {
        if (i > 0) {
            y.push_back(i);
        } else {
            y.push_back(0);
        }
    }
    return y;
}

vector<float> Layer::actFnGrad(vector<float> x) {
    vector<float> y;

    if (this->act_fn == "relu") {
        for (float i : x) {
            if (i > 0) {
                y.push_back(1);
            } else {
                y.push_back(0);
            }
        }
    } else if (this->act_fn == "sigmoid") {
        for (float i : x) {
            y.push_back(i * (1 - i));
        }
    }

    return y;
}

vector<float> Layer::lossFnGrad(vector<float> x) {
    vector<float> y;
    return y;
}

vector<float> Layer::sigmoid(vector<float> x) {
    vector<float> y;

    for (float i : x) {
        y.push_back(1 / (1 + exp(-i)));
    }
    return y;
}

void Layer::backProp_L(float lr, vector<float> y = vector<float>{}) {
    vector<float> tmp;

    if (this->type == "output") {
        tmp = vectElementMul(lossFnGrad(this->l_y_hat), actFnGrad(this->l_y_hat));
    } else {
        
    }

    for (int i = 0; i < this->units; i++) {
        for (int j = 0; j < this->input.size(); j++) {
            this->dW[i][j] = tmp[j] * this->input[j];
        }
    }

    for (int i = 0; i < this->weights.size(); i++) {
        for (int j = 0; j < this->weights[0].size(); j++) {
            this->weights[i][j] -= lr * this->dW[i][j];
        }
    }
}
