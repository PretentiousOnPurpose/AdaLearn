#include <iostream>
#include "seq.hpp"
#include "data.hpp"
#include <string>
#include "utils.hpp"

using namespace std;

int main() {

    DataIterator d = DataIterator(1, "min_max_scaler");
    d.readData("data.csv", "y.csv");
    d.transformData();

    // vector<vector<float>> x = {{1}};
    // vector<vector<float>> y = {{2}};

    Sequential model;
    model.add(2, "relu", 1);
    model.add(3, "relu");
    model.add(1, "relu");

    model.compile(0.05, "mean_squared_error");
    model.fit(x, y, 10);

    return 0;
}
