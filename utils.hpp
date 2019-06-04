#include <vector>
using namespace std;
using std::vector;

vector<float> squareDiff(vector<float>, vector<float>);
vector<float> sub(vector<float>, vector<float>, float = 1.0);
vector<float> add(vector<float>, vector<float>, float = 1.0);
vector<float> mul(vector<float>, vector<float>);
float mean(vector<float>, float = 1.0);
vector<float> vectElementMul(vector<float>, vector<float>);
vector<float> matMul(vector<vector<float>>, vector<float>);
vector<vector<float>> transpose(vector<vector<float>>);
vector<vector<float>> gradMatMul(vector<float>, vector<float>);
void printVect(vector<float>);
void printVect(vector<vector<float>>);
vector<vector<float>> ones_like(vector<vector<float>>);
vector<float> ones_like(vector<float>);
vector<float> getMatDims(vector<vector<float>>);
vector<float> scale(float, vector<float>);
vector<float> gradSum(vector<vector<float>>, vector<float>);
