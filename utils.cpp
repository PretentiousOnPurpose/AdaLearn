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

vector<float> add(vector<float> x, vector<float> y, float scale) {
    vector<float> z;
    
    for (int i = 0; i < x.size(); i++) {
            z.push_back(scale * (x[i] + y[i]));
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

vector<vector<float>> gradMatMul(vector<float> x1, vector<float> x2) {
    vector<vector<float>> y;
    for (int i = 0; i < x1.size(); i++) {
        vector<float> tmp;
        for (int j = 0; j < x2.size(); j++) {
            tmp.push_back(x1[i] * x2[j]);
        }
        y.push_back(tmp);
    }

    return y;
}

vector<vector<float>> transpose(vector<vector<float>> w) {
    vector<vector<float>> y;
    for (int i = 0; i < w[0].size(); i++) {
        vector<float> tmp;
        for (int j = 0; j < w.size(); j++) {
            tmp.push_back(w[j][i]);
        }

        y.push_back(tmp);
    }

    return y;
}

void printVect(vector<float> x) {
    for (float i : x) {
        cout << i << ",";
    }
    cout << endl;
}

void printVect(vector<vector<float>> x) {
    for (vector<float> i : x) {
        for (float j : i) {
            cout << j << ",";
        }
        cout << endl;
    }
}

vector<int> getMatDims(vector<vector<float>> x) {
    vector<int> y;
    y.push_back(x.size());
    y.push_back(x[0].size());
    
    return y;
}

vector<vector<float>> ones_like(vector<vector<float>> x) {
    vector<vector<float>> w;
    vector<int> dims = getMatDims(x);

    for (int i = 0; i < dims[0]; i++) {
        vector<float> tmp;
        for (int j = 0; j < dims[1]; j++) {
            tmp.push_back(1);
        }
        w.push_back(tmp);
    }

    return w;
}

vector<float> ones_like(vector<float> x) {
    vector<float> w;

    for (int i = 0; i < x.size(); i++) {
        w.push_back(1);
    }

    return w;
}

vector<float> scale(float s, vector<float> x) {
    vector<float> y;
    for (float i : x) {
        y.push_back(s * i);
    }

    return y;
}

float gradSum(vector<vector<float>> w, vector<float> dErr) {
    float sum = 0;
    vector<float> tmp = matMul(transpose(w), dErr);

    for (float i : tmp) {
        sum += i;
    }

    return sum;

}

vector<vector<float>> zeros(int x, int y) {
    vector<vector<float>> z;
    vector<float> tmp;

    for (int i = 0; i < y; i++) {
        tmp.push_back(0);
    }

    for (int i = 0; i < x; i++) {
        z.push_back(tmp);
    }

    return z;
}

vector<float> zeros(int x) {
    vector<float> y;

    for (int i = 0; i < x; i++) {
        y.push_back(0);
    }

    return y;
}