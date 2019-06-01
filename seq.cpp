#include <iostream>
#include "seq.hpp"
#include <string>
#include <cmath>
#include <vector>
#include "utils.hpp"

using std::vector;
using namespace std;

void Sequential::add(int units, string act_fn, int input_dims) {
    auto L = Layer(units, act_fn, (int)(this->layers.size()+1));
    if (input_dims) {
        this->dims.push_back(input_dims);
        L.initWeights(input_dims);
        L.type = "input";
    } else {
        this->layers.back().type = "hidden";
        L.initWeights(this->dims.back());
        L.type = "output";
    }

    this->dims.push_back(units);
    this->layers.push_back(L);
}

void Sequential::run(vector<float> x) {
    this->layers[0].activation(x);
    for (int i = 1; i < this->layers.size(); i++) {
        this->layers[i].activation(this->layers[i - 1].l_y_hat);
    }

    this->y_hat = this->layers.back().l_y_hat;
}

void Sequential::compile(float lr, string loss_fn, int print_freq) {
    this->lr = lr;
    this->loss_fn = loss_fn;
    this->print_freq = print_freq;
    this->layers[0].type = "input";
}

void Sequential::fit(vector<vector<float>> x, vector<vector<float>> y, int epochs) {
    for (int e = 0; e < epochs; e++) {
        float loss = 0;
        for(int i = 0; i < x.size(); i++) {
            this->run(x[i]);

            // cout << "Y" << endl;
            // printVect(y[i]);

            // cout << "Y_HAT" << endl;
            // printVect(this->y_hat);
            
            loss += this->getLoss(y[i]);
            this->backProp(this->lr, this->loss_fn, y[i]);

            // cin.ignore();

            // cout << "\n\nHit Return or Enter for Main Screen\n\n";            
            // while (cin.get() != '\n') {}
        }
        loss /= x.size();

        if (e % this->print_freq == 0) {
            cout << "Epoch - " << e << " | Loss: " << loss << endl;
        }

    }
}

void Sequential::backProp(float lr, string loss_fn, vector<float> y) {
    this->layers.back().backProp_L(lr, loss_fn, y, vector<vector<float>>{});
    for (int i = this->layers.size() - 2; i >= 0; i--) {
        this->layers[i].backProp_L(lr, loss_fn, this->layers[i+1].dErr, this->layers[i+1].weights);
    }
}

float Sequential::getLoss(vector<float> y) {
    float loss = 0;

    if (this->loss_fn == "mean_squared_error") {
        for (int i = 0; i < y.size(); i++) {
            loss += (y[i] - this->y_hat[i]) * (y[i] - this->y_hat[i]);
        }
        loss /= y.size();
    } else if (this->loss_fn == "binary_cross_entropy") {
        for (int i = 0; i < y.size(); i++) {
            loss -= (y[i] * log(0.001 + this->y_hat[i]) + (1 - y[i]) * log(0.001 + 1 - this->y_hat[i]));
        }

        loss /= y.size();        
    }

    return loss;
}

void Sequential::accuracy(vector<vector<float>> x, vector<vector<float>> y) {
    float acc = 0;
    for (int i = 0; i < x.size(); i++) {
        this->run(x[i]);
        if ((this->y_hat[0] > 0.5 && y[i][0] == 1) || (this->y_hat[0] <= 0.5 && y[i][0] == 0)) {
            acc++;
        }
    }

    cout << "Acc: " << acc / x.size() << endl;
}