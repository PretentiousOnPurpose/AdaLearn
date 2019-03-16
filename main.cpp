#include <iostream>
#include "seq.hpp"
#include <string>
#include <type_traits>
#include <typeinfo>

using namespace std;

int main() {

    Sequential model;
    model.Add(10, "relu", 5);
    model.Add(15, "relu");
    model.Add(5, "relu");
    model.Add(1, "sigmoid");

    return 0;
}