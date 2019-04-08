#include <vector>
#include <string>
#include "layers.hpp"

using std::vector;
using namespace std;

class Sequential {
    public:
        vector<Layer> layers;
        vector<float> y_hat;
        vector<int> dims;
        string loss_fn;
        float lr;
        int print_freq;

        void add(int units, string act_fn, int input_dims = 0);
        void run(vector<float>);
        void compile(float, string, int = 1);
        void fit(vector<vector<float>>, vector<vector<float>>, int);
        float getLoss(vector<float>);
        void backProp(float, string, vector<float>);
};
