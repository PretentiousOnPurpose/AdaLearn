#include <iostream>
#include "seq.hpp"
#include "data.hpp"
#include <string>
#include "utils.hpp"

using namespace std;

int main() {

    DataIterator d = DataIterator(1, "standard_scaler");
    d.readData("data.csv", "y.csv");
    d.transformData();

    Sequential model;
    model.add(1, "relu", 1);
    // model.add(3, "relu");
    // model.add(1, "relu");

    model.compile(0.05, "mean_squared_error");
    model.fit(d.tX, d.tY, 5);



    // model.run()

    return 0;
}
