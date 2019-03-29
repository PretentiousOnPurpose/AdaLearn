#include <vector>
#include <iostream>
#include "utils.hpp"

using namespace std;
using std::vector;

vector<float> squareDiff(vector<float> x, vector<float> y) {
    vector<float> z;

    if (x.size() == y.size()) {
        for (int i = 0; i < x.size(); i++) {
            z.push_back((x[i] - y[i]) * (x[i] - y[i]));
        }
    }

    return z;
}

vector<float> Sub(vector<float> x, vector<float> y) {
    vector<float> z;

    if (x.size() == y.size()) {
        for (int i = 0; i < x.size(); i++) {
            z.push_back(x[i] - y[i]);
        }
    }

    return z;
}

vector<float> Mul(vector<float> x, vector<float> y) {
    vector<float> z;

    if (x.size() == y.size()) {
        for (int i = 0; i < x.size(); i++) {
            z.push_back(x[i] * y[i]);
        }
    }

    return z;
}

vector<float> matMul(vector<vector<float>> w, vector<float> x) {
    vector<float> y;
    float tmp;

    for (int i = 0; i < w.size(); i++) {
        tmp = 0;
        for (int j = 0; j < w[0].size(); j++) {
            tmp += x[j] * w[i][j];
        }
        y.push_back(tmp);
    }

    return y;
}