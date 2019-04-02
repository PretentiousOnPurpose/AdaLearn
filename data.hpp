#include <string>
#include <vector>
using namespace std;
using std::vector;

class DataIterator {
    public:
        int n_feat;
        string type;
        vector<float> meanX;
        vector<float> stdX;
        
        vector<float> minX;
        vector<float> maxX;
        

        float meanY;
        float stdY;

        float minY;
        float maxY;

        vector<vector<float>> rX;
        vector<vector<float>> rY;
        vector<vector<float>> tX;
        vector<vector<float>> tY;

        vector<float> strSplit(char * , string);

        void readData(string, string);
        void transformData();
        void standardScaler();
        void minMaxScaler();
        vector<float> inverseTransformX(vector<float>);
        vector<float> inverseTransformY(vector<float>);

        DataIterator(int n_feat, string type) {
            this->n_feat = n_feat;
            this->type = type;
        }
};
