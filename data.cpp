#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "data.hpp"

using namespace std;
using std::vector;

vector<float> DataIterator::strSplit(char * x, string delim) {
    vector<float> y;
    char * token = strtok(x,",");
    
    while (token != NULL) {
        y.push_back(stof(token));
        token = strtok (NULL, ",");
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