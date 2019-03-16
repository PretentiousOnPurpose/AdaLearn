#include <vector>
#include <string>
#include "layers.hpp"

using std::vector;

class Sequential {
    public:
        vector<Layer> layers;
        vector<int> dims;
        
        void Add(int units, string act_fn, int input_dims = 0);

        void Fit();

        void predict();
}