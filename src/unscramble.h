#ifndef UNSCRAMBLE_H
#define UNSCRAMBLE_H

#include "readDict.h"
#include <string>
#include <vector>

using namespace std;

class Unscrambler {
    private:
        Dictionary dict;
        int checkChar(char chr, string otherword);
        bool checkWord(string word, string otherword);

    public:
        Unscrambler(Dictionary dictionary);
        vector<string> unscramble(string word);
};

#endif
