#include <vector>
#include <string>
#include <cmath>
using std::vector;
using namespace std;


class Layer {
    public:
        string act_fn;
        vector<float> dErr;
        vector<vector<float>> weights;
        vector<vector<float>> dW;
        vector<float> bias;
        vector<float> dB;
        vector<float> l_y_hat;
        vector<float> input;
        int units;
        string type;
        int n;

        Layer(int units, string act_fn, int n);
        void activation(vector<float>);
        vector<float> relu(vector<float>);
        vector<float> sigmoid(vector<float>);
        void initWeights(int input_dims);
        void readWeights(int, int, int);
        vector<float> actFnGrad(vector<float>, int = 0);
        vector<float> lossFnGrad(vector<float>, string);
        void backProp_L(float, string, vector<float>, vector<vector<float>>);
};
