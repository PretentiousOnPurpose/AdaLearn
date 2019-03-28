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
    model.Add(1, "relu", 5);

    DataIterator d = DataIterator(4);

    d.readData("data.csv", "y.csv");

    cout << d.rX[5][2] << endl;

    return 0;
}