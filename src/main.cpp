#include "readDict.h"
#include "unscramble.h"
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout << "usage: unscramble <word> [-d dictionary-file]" << endl;
        return 1;
    }
    string dictpath = "dict/american-english";
    string word = "";
    for (int i = 1; i < argc; i++) {
        if (((string)argv[i] == "-d" || (string)argv[i] == "--dict") && i != argc - 1) {
            dictpath = argv[i + 1];
            i++;
        }
        else if (word == "") {
            word = argv[i];
        }
    }
    if (word == "") {
        cout << "error: no word given" << endl;
        return 1;
    }
    Dictionary dict;
    try {
        dict = Dictionary(dictpath);
    }
    catch (runtime_error& e) {
        cout << "error: failed to open dictionary file" << endl;
        return 1;
    }
    Unscrambler unscrambler = Unscrambler(dict);
    vector<string> words = unscrambler.unscramble(word);
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << endl;
    }
    return 0;
}
