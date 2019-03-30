#include <iostream>
#include "seq.hpp"
#include "data.hpp"
#include <string>

using namespace std;

int main() {

    Sequential model;
    model.Add(10, "relu", 5);
    model.Add(25, "relu");
    model.Add(50, "relu");
    model.Add(30, "relu");
    model.Add(15, "relu");
    model.Add(5, "relu");
    model.Add(1, "relu");

    model.compile(0.01, "mean_squared_error");

    model.fit();

    DataIterator d = DataIterator(4);

    d.readData("data.csv", "y.csv");
    d.transformData();

    return 0;
}
