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
    model.add(1, "relu", d.n_feat);
    model.add(5, "relu");
    model.add(3, "relu");
    model.add(1, "relu");

    model.compile(0.05, "mean_squared_error", 10);
    model.fit(d.tX, d.tY, 10);

    model.run(d.tX[92]);
    printVect(d.inverseTransformY(model.y_hat));
    printVect(d.rY[92]);

    return 0;
}
