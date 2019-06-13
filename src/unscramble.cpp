#include "unscramble.h"
#include "readDict.h"
#include <string>
#include <vector>

using namespace std;

Unscrambler::Unscrambler(Dictionary dictionary) {
    dict = dictionary;
}

int Unscrambler::checkChar(char chr, string otherword) {
    for (int i = 0; i < otherword.length(); i++) {
        if (chr == otherword[i]) {
            return i;
        }
    }
    return -1;
}

bool Unscrambler::checkWord(string word, string otherword) {
    if (word.length() != otherword.length()) {
        return false;
    }
    int index;
    for (int i = 0; i < word.length(); i++) {
        index = checkChar(word[i], otherword);
        if (index != -1) {
            otherword.erase(otherword.begin() + index);
        }
        else {
            return false;
        }
    }
    return true;
}

vector<string> Unscrambler::unscramble(string word) {
    vector<string> words;
    for (int i = 0; i < dict.size(); i++) {
        if (checkWord(word, dict.get(i))) {
            words.push_back(dict.get(i));
        }
    }
    return words;
}
