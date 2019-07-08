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
    model.add(3, "relu");
    model.add(4, "relu");
    model.add(2, "relu");
    model.add(1, "relu");

    model.compile(0.0025, "mean_squared_error", 500);
    model.fit(d.tX, d.tY, 4000);

    model.run(d.transformX(vector<float>{0.4}));
    printVect(d.inverseTransformY(model.y_hat));

    return 0;
}
