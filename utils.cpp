#include <iostream>
#include <cmath>
#include "utils.hpp"
using namespace std;

vector<float> relu(vector<float> x) {
    vector<float> y;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] >= 0) {
            y.push_back(x[i]);
        } else {
            y.push_back(0);
        }
    }
}

vector<float> sigmoid(vector<float> x) {
    vector<float> y;
    for (int i = 0; i < x.size(); i++) {
        y.push_back(1 / (1 + exp(-x[i])));
    }
}