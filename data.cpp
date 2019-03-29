#include <string.h>
#include <cmath>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "data.hpp"

using namespace std;
using std::vector;

vector<float> DataIterator::strSplit(char * x, string delim) {
    vector<float> y;
    char * token = strtok(x,",");

    while (token != NULL) {
        y.push_back(stof(token));
        token = strtok(NULL, ",");
    }

    return y;
}

void DataIterator::readData(string x_data_filename, string y_data_filename) {
    ifstream x_file (x_data_filename);
    ifstream y_file (y_data_filename);

    string line;

    if (x_file.is_open()) {
        while (getline(x_file,line)) {
            this->rX.push_back(this->strSplit(const_cast<char*>(line.c_str()), ","));
        }
        x_file.close();
    }

    if (y_file.is_open()) {
        while (getline(y_file,line)) {
            this->rY.push_back(this->strSplit(const_cast<char*>(line.c_str()), ","));
        }
        y_file.close();
    }

}

void DataIterator::transformData() {

    // For X_DATA
    // Calculating Mean
    for (int i = 0; i < this->n_feat; i++) {
        float mean = 0;
        for (int j = 0; j < this->rX.size(); j++) {
            mean += this->rX[j][i];
        }

        this->meanX.push_back(mean / this->rX.size());
    }

    // Calculating Std Deviation
    for (int i = 0; i < this->n_feat; i++) {
        float std = 0;
        for (int j = 0; j < this->rX.size(); j++) {
            std += (this->rX[j][i] - this->meanX[i]) * (this->rX[j][i] - this->meanX[i]);
        }

        std /= this->rX.size();
        std = sqrt(std);

        this->stdX.push_back(std);
    }

    // Transformation
    for (int i = 0; i < this->rX.size(); i++) {
        vector<float> tmp;
        for (int j = 0; j < this->n_feat; j++) {
            tmp.push_back((this->rX[i][j] - this->meanX[j]) / this->stdX[j]);
        }

        this->tX.push_back(tmp);
    }


    // For Y_DATA
    // Calculating Mean
    float mean = 0;
    for (int i = 0; i < this->rY.size(); i++) {
        mean += this->rY[i][0];
    }
    this->meanY = mean / this->rY.size();

    // Calculating Std Deviation
    float std = 0;
    for (int i = 0; i < this->rX.size(); i++) {
        std += (this->rY[i][0] - this->meanY) * (this->rY[i][0] - this->meanY);
    }

    std /= this->rY.size();
    std = sqrt(std);

    this->stdY = std;

    // Transformation
    for (int i = 0; i < this->rY.size(); i++) {
        this->tY.push_back((this->rY[i][0] - this->meanY) / this->stdY);
    }
}

vector<float> DataIterator::inverseTransformX(vector<float> x) {
    vector<float> y;
    if (x.size() == this->n_feat) {
        for (int i = 0; i < n_feat; i++) {
            y.push_back(x[i] * this->stdX[i] + this->meanX[i]);
        }
    } else {
        cout << "No Sufficient Input Features" << endl;
        exit(0);
    }

    return y;
}

vector<float> DataIterator::inverseTransformY(vector<float> x) {
    vector<float> y;
    for (int i = 0; i < n_feat; i++) {
        y.push_back(y[i] * this->stdY + this->meanY);
    }

    return y;
}
