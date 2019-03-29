#include <iostream>
#include "seq.hpp"
#include "data.hpp"
#include <string>

using namespace std;

int main() {

    Sequential model;
    model.Add(10, "relu", 5);
    model.Add(15, "relu");
    model.Add(5, "relu");
    model.Add(1, "relu");

    DataIterator d = DataIterator(4);

    d.readData("data.csv", "y.csv");
    d.transformData();

    cout << d.meanY << endl;

    return 0;
}