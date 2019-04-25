#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <random>
#include <fstream>
#include "layers.hpp"
#include "utils.hpp"
#include "data.hpp"

using std::vector;
using namespace std;

Layer::Layer(int units, string act_fn, int n) {
    this->units = units;
    this->act_fn = act_fn;
    this->n = n;
}

void Layer::readWeights(int x, int y, int wb) {
    string cmd = "python3 rand_gen.py " + to_string(x) + " " + to_string(y) + " > rand_gen.txt";
    system(cmd.c_str());

    ifstream x_file ("rand_gen.txt");

    string line;

    if (x_file.is_open()) {
        while (getline(x_file,line)) {
            if (wb) {
                this->weights.push_back(DataIterator::strSplit(const_cast<char*>(line.c_str()), ","));
            } else {
                this->bias = DataIterator::strSplit(const_cast<char*>(line.c_str()), ",");
            }
        }
        x_file.close();
    }

}

void Layer::initWeights(int input_dims) {    
    readWeights(this->units, input_dims, 1);
    readWeights(this->units, 1, 0);
}

void Layer::activation(vector<float> x) {

    this->input = x;
    vector<float> y = add(matMul(this->weights, x), this->bias);

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

vector<float> Layer::actFnGrad(vector<float> x, int o) {
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
            if (!o) {
                y.push_back(i * (1 - i));
            } else {
                y.push_back((i) * (1 - (i)));
            }
        }
    }

    return y;
}

vector<float> Layer::lossFnGrad(vector<float> x, string loss_fn) {
    vector<float> y;

    if (loss_fn == "mean_squared_error") {
        return sub(this->l_y_hat, x);
    } else if (loss_fn == "binary_cross_entropy") {
        for (int i = 0; i < x.size(); i++) {
            y.push_back(-(this->l_y_hat[i] - x[i]) / ((this->l_y_hat[i]) * (1 - (this->l_y_hat[i]))));
        }
    }

    return y;
}

vector<float> Layer::sigmoid(vector<float> x) {
    vector<float> y;

    for (float i : x) {
        y.push_back(1 / (1 + exp(-i)));
    }
    return y;
}

void Layer::backProp_L(float lr, string loss_fn, vector<float> dErr_1, vector<vector<float>> w) {
    
    float tmp = 0;
    vector<float> tmp1;
    vector<vector<float>> dW;
    
    if (this->type == "output" || (this->type == "input" && w.empty())) {
        this->dErr = vectElementMul(lossFnGrad(dErr_1, loss_fn), actFnGrad(this->l_y_hat));
    } else {
        this->dErr = vectElementMul(matMul(transpose(w), dErr_1), actFnGrad(this->l_y_hat));        
    }

    // cout << "-------- Layer " << this->n << " -----------" << endl;

    // cout << "In" << endl;
    // printVect(this->input);

    // cout << "W" << endl;
    // printVect(this->weights);

    // cout << "B" << endl;
    // printVect(this->bias);

    // cout << "db" << endl;
    // printVect(this->dErr);

    dW = gradMatMul(this->dErr, this->input);

    for (int i = 0; i < this->weights.size(); i++) {
        for (int j = 0; j < this->weights[0].size(); j++) {
            this->weights[i][j] = this->weights[i][j] - lr * dW[i][j];
        }
    }

    for (int i = 0; i < this->units; i++) {
        this->bias[i] -= lr * this->dErr[i];
    }

    // cout << "dW" << endl;
    // printVect(dW);

    // cout << "W+" << endl;
    // printVect(this->weights);

    // cout << "b+" << endl;
    // printVect(this->bias);

    // cout << "-------- Layer " << this->n << " -----------" << endl;

}