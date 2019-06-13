#include "readDict.h"
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

using namespace std;

Dictionary::Dictionary(string filename) {
    ifstream dictfile(filename);
    string line;
    if (dictfile.is_open()) {
        while (getline(dictfile, line)) {
            dict.push_back(line);
        }
        dictfile.close();
    }
    else {
        throw runtime_error("unable to read file");
    }
}

int Dictionary::size() {
    return dict.size();
}

string Dictionary::get(int index) {
    return dict[index];
}

void Dictionary::remove(int index) {
    dict.erase(dict.begin() + index);
}
