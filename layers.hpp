#include <vector>
#include <string>

using std::vector;

class Layer {
    public:
        string act_fn;
        vector<float> weights;
        int inDim[2];
        int outDim[2];

        Layer(int units, string act_fn);
        initWeight(int input_dims);
};