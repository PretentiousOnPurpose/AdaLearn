#include <string>
#include <vector>
using namespace std;
using std::vector;

class DataIterator {
    public:
        int n_feat;
        
        vector<float> minX;
        vector<float> maxX;
        vector<float> stdX;

        float minY;
        float maxY;
        float stdY;

        vector<vector<float>> rX;    
        vector<vector<float>> rY;
        vector<vector<float>> tX;    
        vector<vector<float>> tY;

        vector<float> strSplit(char * , string);

        void readData(string, string);
        void transformData();
        vector<float> inverseTransform(vector<float>);

        DataIterator(int n_feat) {
            this->n_feat = n_feat;
        }
};