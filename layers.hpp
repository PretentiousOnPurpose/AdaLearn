#include <vector>
#include <string>
#include <cmath>
using std::vector;
using namespace std;


class Layer {
    public:
        string act_fn;
        vector<vector<float>> dW;
        vector<float> dErr;
        vector<vector<float>> weights;
        vector<float> l_y_hat;
        vector<float> input;
        int units;
        string type;

        Layer(int units, string act_fn, string type);
        void activation(vector<float>);
        vector<float> relu(vector<float>);
        vector<float> sigmoid(vector<float>);
        void initWeights(int input_dims);
        vector<float> actFnGrad(vector<float>);
        vector<float> lossFnGrad(vector<float>, string);
        void backProp_L(float, string, vector<float>);
};
