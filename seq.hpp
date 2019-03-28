#include <vector>
#include <string>
#include "layers.hpp"

using std::vector;
using namespace std;

class Sequential {
    public:
        vector<Layer> layers;
        vector<int> dims;
        vector<float> y_hat;
        
        void Add(int units, string act_fn, int input_dims = 0);
        void Run(vector<float>);

        void Fit(vector<float>, vector<float>, int);
        void backProp();
        void predict(vector<float>);
};