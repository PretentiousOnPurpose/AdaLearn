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

vector<float> sub(vector<float> x, vector<float> y, float scale) {
    vector<float> z;
    
    for (int i = 0; i < x.size(); i++) {
            z.push_back(scale * (x[i] - y[i]));
    }

    return z;
}

vector<float> mul(vector<float> x, vector<float> y) {
    vector<float> z;

    if (x.size() == y.size()) {
        for (int i = 0; i < x.size(); i++) {
            z.push_back(x[i] * y[i]);
        }
    }

    return z;
}

float mean(vector<float> x, float scale) {
    float mean = 0;
    for (float i : x) {
        mean += scale * i;
    }

    mean /= x.size();
    return mean;
}

vector<float> vectElementMul(vector<float> x1, vector<float> x2) {
    vector<float> y;

    if (x1.size() == x2.size()) {
        for (int i = 0; i < x1.size(); i++) {
            y.push_back(x1[i] * x2[i]);
        }
    }

    return y;
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

void printVect(vector<float> x) {
    for (float i : x) {
        cout << i << " ";
    }
    cout << endl;
}

void printVect(vector<vector<float>> x) {
    for (vector<float> i : x) {
        for (float j : i) {
            cout << j << " ";
        }
        cout << endl;
    }
}

