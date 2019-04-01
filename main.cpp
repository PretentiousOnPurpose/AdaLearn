#include <iostream>
#include "seq.hpp"
#include "data.hpp"
#include <string>
#include "utils.hpp"

using namespace std;

int main() {

    DataIterator d = DataIterator(4);
    d.readData("data.csv", "y.csv");
    d.transformData();

    Sequential model;
    model.add(10, "relu", 2);
    model.add(20, "relu");
    model.add(15, "relu");
    model.add(5, "relu");
    model.add(1, "relu");

    model.compile(0.01, "mean_squared_error");
    model.fit(d.tX, d.tY, 2);

    return 0;
}
