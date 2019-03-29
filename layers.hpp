#include <vector>
#include <string>
#include <cmath>
using std::vector;
using namespace std;


class Layer {
    public:
        string act_fn;
        vector<float> dW;
        vector<vector<float>> weights;
        vector<float> l_y_hat;
        int units;
        string type;

        Layer(int units, string act_fn, string type);
        void activation(vector<float>);
        vector<float> relu(vector<float>);
        vector<float> sigmoid(vector<float>);
        void initWeights(int input_dims);

        void backProp_L(vector<float>);
};
