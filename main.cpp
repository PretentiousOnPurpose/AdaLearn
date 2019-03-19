#include <iostream>
#include "seq.hpp"
#include <string>

using namespace std;

int main() {

    // Sequential model;
    // model.Add(10, "relu", 5);
    // model.Add(15, "relu");
    // model.Add(5, "relu");
    // model.Add(1, "sigmoid");

    Layer l = Layer(10, "relu");
    l.initWeights(5);
    

    return 0;
}