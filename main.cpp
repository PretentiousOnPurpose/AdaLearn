#include <iostream>
#include "seq.hpp"
#include "data.hpp"
#include <string>
#include "utils.hpp"

using namespace std;


int main() {


    DataIterator d = DataIterator("min_max_scaler");
    d.readData("linX.csv", "linY.csv");
    d.transformData();

    Sequential model;
    model.add(1, "relu", d.n_feat);
    model.add(2, "relu");
    model.add(3, "relu");
    model.add(1, "relu");

    model.compile(0.005, "mean_squared_error", 10);
    model.fit(d.tX, d.tY, 500, 50);

    // model.run(d.transformX(vector<float>{10}));

    // model.accuracy(d.tX, d.rY);

    return 0;
}