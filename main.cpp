#include <iostream>
#include "seq.hpp"
#include "data.hpp"
#include <string>
#include "utils.hpp"

using namespace std;

int main() {

    DataIterator d = DataIterator(30, "min_max_scaler");
    d.readData("trainX.csv", "trainY.csv");
    d.transformData();

    vector<vector<float>> x = {{0, 0}, {0, 1}, {1, 0}, {1, 1}, {1, 3}, {3, -1}, {-1, 1},  {1, 2}, {2, 1}, {2, 2}, {2, 3}, {3, 2}};
    vector<vector<float>> y = {{0}, {0}, {0}, {0}, {1}, {0}, {0}, {1}, {1}, {1}, {1}, {1}};

    Sequential model;
    model.add(1, "relu", 2);
    model.add(5, "relu");
    model.add(3, "relu");
    model.add(1, "sigmoid");

    model.compile(0.005, "binary_cross_entropy");
    model.fit(x, y, 330);

    model.run(vector<float>{1,1});
    printVect(model.y_hat);

        model.run(vector<float>{0,1});
    printVect(model.y_hat);

        model.run(vector<float>{1,0});
    printVect(model.y_hat);

        model.run(vector<float>{5,5});
    printVect(model.y_hat);

    return 0;
}
