#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <random>
#include "layers.hpp"

using std::vector;
using namespace std;

Layer::Layer(int units, string act_fn) {
    this->units = units;
    this->act_fn = act_fn;
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
