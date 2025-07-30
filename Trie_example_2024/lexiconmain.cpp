#include <iostream>
#include <fstream>
#include "shplexicon.h"

using namespace std;

int main() {
    cout << "Hello, SHP Lexicon!" << endl;
    shplexicon words;
    ifstream fin("words.txt");
    string word;
    while (!fin.eof()) {
        fin >> word;
        words.insert(word);
    }
    cout << words.size() << endl;
    string input = " ";
    while (input != "quit") {
        cout << "Input: " ;
        cin >> input;
        if (words.containsWord(input))
            cout << "Yes, it's a word." << endl;
        else
            cout << "No, it's not a word." << endl;
        if (words.containsPrefix(input))
            cout << "Yes, it's a prefix." << endl;
        else
            cout << "No, it's not a prefix." << endl;
    }

    return 0;
}