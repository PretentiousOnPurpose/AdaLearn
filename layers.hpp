#include <vector>
#include <string>

using std::vector;
using namespace std;


class Layer {
    public:
        string act_fn;
        vector<vector<float>> weights;
        int units;

        Layer(int units, string act_fn);
        void initWeight(int input_dims);
};