#include <iostream>
#include "seq.hpp"
#include "data.hpp"
#include <string>
#include "utils.hpp"

using namespace std;


int main() {


    DataIterator d = DataIterator("min_max_scaler");
    d.readData("dataX.csv", "dataY.csv");
    d.transformData();

    Sequential model;
    model.add(1, "relu", d.n_feat);
    // model.add(2, "relu");
    // model.add(3, "relu");
    // model.add(1, "relu");

    model.compile(0.5, "mean_squared_error", 25);
    model.fit(d.tX, d.tY, 100);

    model.run(d.transformX(vector<float>{0.78, 0.45, 0.21}));
    printVect(d.inverseTransformY(model.y_hat));


    printVect(model.layers[0].weights);
    // model.accuracy(d.tX, d.rY);

    return 0;
}
