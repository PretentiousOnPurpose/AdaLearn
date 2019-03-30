#include <vector>
#include <string>
#include "layers.hpp"

using std::vector;
using namespace std;

class Sequential {
    public:
        vector<Layer> layers;
        vector<float> y_hat;

        string loss_fn;
        float lr;

        void add(int units, string act_fn, int input_dims = 0);
        void run(vector<float>);
        void compile(float, string);
        void fit(vector<float>, vector<float>, int);
        void backProp(vector<float>, vector<float>);
        void predict(vector<float>);
};
