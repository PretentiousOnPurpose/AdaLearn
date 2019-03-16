#include <iostream>
#include "seq.hpp"
#include <vector>

using std::vector;
using namespace std;

void Sequential::Add(int units, string act_fn, int input_dims = 0) {
    auto L = Layer(units, act_fn);
    Sequential::layers.push_back(L);
    if (input_dims) {
        L.initWeight(input_dims);
    } else {
        L.initWeight(Sequential::dims.back());
    }
    Sequential::dims.push_back(units);
}