#include <string>
#include <vector>
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

        void readData(string, string);
        void transformData();
        vector<float> inverseTransform(vector<float>);
};