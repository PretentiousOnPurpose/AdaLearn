#include <iostream>
#include "seq.hpp"
#include <string>

using namespace std;

int main() {

    Sequential model;
    // model.Add(10, "relu", 5);
    // model.Add(15, "relu");
    // model.Add(5, "relu");
    model.Add(1, "relu", 5);

    vector<float> x = {1, 0, 1, 0, 1};

    model.Run(x);
    for (int i = 0; i < model.layers[0].weights.size(); i++) {
        for (int j = 0; j < model.layers[0].weights[0].size(); j++) {
            cout << model.layers[0].weights[i][j] << " ";
        }
    }

    cout << endl << model.y_hat[0] << endl;

    return 0;
}