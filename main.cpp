#include <iostream>
#include "seq.hpp"
#include "data.hpp"
#include <string>
#include "utils.hpp"

using namespace std;


int main() {


    DataIterator d = DataIterator("min_max_scaler");
    d.readData("data.csv", "y.csv");
    d.transformData();

    Sequential model;
    model.add(1, "relu", 5);
    model.add(2, "relu");
    model.add(3, "relu");
    model.add(1, "relu");

    model.compile(0.00075, "mean_squared_error", 50);
    model.fit(d.tX, d.tY, 500);

    // model.run(d.transformX(vector<float>{10}));

    // model.accuracy(d.tX, d.rY);

    return 0;
}