#include <vector>
#include <string>
#include <cmath>
using std::vector;
using namespace std;


class Layer {
    public:
        string act_fn;
        vector<vector<float>> weights;
        vector<float> l_y_hat;
        int units;

        Layer(int units, string act_fn);
        void activation(vector<float>);
        vector<float> relu(vector<float>);
        vector<float> sigmoid(vector<float>);
        void initWeights(int input_dims);

        void backProp_L();
};
