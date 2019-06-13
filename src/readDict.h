#ifndef READDICT_H
#define READDICT_H

#include <string>
#include <vector>

using namespace std;

class Dictionary {
    private:
        vector<string> dict;
    
    public:
        Dictionary() = default;
        Dictionary(string filename);
        int size();
        string get(int index);
        void remove(int index);
};

#endif
