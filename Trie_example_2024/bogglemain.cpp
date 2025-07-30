#include <iostream>
#include <fstream>
#include <ctime>
#include "shplexicon.h"

using namespace std;

void printWordHelper(int r, int c, string guess, const shplexicon & words, const char grid[5][5]) {
    if (r < 0 || r > 4 || c < 0 || c > 4)
        return;
    if(!words.containsPrefix(guess))
        return;
    guess += grid[r][c];
        if (guess.length() >= 3 && words.containsWord(guess))
            cout << guess << endl;
        printWordHelper(r + 1, c, guess, words, grid);
        printWordHelper(r + 1, c + 1, guess, words, grid);
        printWordHelper(r + 1, c - 1, guess, words, grid);
        printWordHelper(r, c + 1, guess, words, grid);
        printWordHelper(r, c - 1, guess, words, grid);
        printWordHelper(r - 1, c, guess, words, grid);
        printWordHelper(r - 1, c + 1, guess, words, grid);
        printWordHelper(r - 1, c - 1, guess, words, grid);

}

void printAllWords(const char table[5][5], const shplexicon & words) {
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++)
            printWordHelper(r, c, "", words, table);
    }
}

int main() {
    srand(time(nullptr));
    shplexicon words;
    ifstream fin("words.txt");
    string word;
    while (!fin.eof()) {
        fin >> word;
        words.insert(word);
    }
    char table[5][5];
    string alphabet = "ABCDEFGHIJKLMNOPRSTUVWXYZ";
    for (int r = 0; r < 5; r++)
        for (int c = 0; c < 5; c++) {
            int index = rand() % alphabet.length();
            table[r][c] = alphabet[index];
            alphabet = alphabet.substr(0, index) + alphabet.substr(index + 1);
        }
    for (int r = 0; r < 5; r++) {
        for (int c = 0; c < 5; c++)
            cout << table[r][c] << "  ";
        cout << endl;
    }
    printAllWords(table, words);
    return 0;
}