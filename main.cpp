#include <iostream>
#include "seq.hpp"
#include "data.hpp"
#include <string>
#include "utils.hpp"

using namespace std;


int main() {

    DataIterator d = DataIterator("min_max_scaler");
    d.readData("trainX.csv", "trainY.csv");
    d.transformData();

    Sequential model;
    model.add(1, "sigmoid", d.n_feat);
    model.add(2, "relu");
    model.add(4, "relu");
    model.add(1, "relu");
    model.add(1, "relu");

    model.compile(0.05, "mean_squared_error", 25);
    model.fit(d.tX, d.rY, 201);

    model.accuracy(d.tX, d.rY);

    return 0;
}