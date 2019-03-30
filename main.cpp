#include <iostream>
#include "seq.hpp"
#include "data.hpp"
#include <string>

using namespace std;

int main() {

    // DataIterator d = DataIterator(4);
    // d.readData("data.csv", "y.csv");
    // d.transformData();

    vector<float> x = {1,1,1,1};
    vector<float> y = {1};

    Sequential model;
    model.add(10, "relu", 4);
    model.add(25, "relu");
    model.add(50, "relu");
    model.add(30, "relu");
    model.add(15, "relu");
    model.add(5, "relu");
    model.add(1, "relu");

    model.compile(0.01, "mean_squared_error");
    model.fit(x, y, 2);

    return 0;
}
