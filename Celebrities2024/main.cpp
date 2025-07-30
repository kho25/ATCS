#include <iostream>
#include <fstream>
#include <vector>

#include "Celebrity.h"
using namespace std;


vector<Celebrity> celebs;

void loadCelebs();

int main() {
    srand(time(0));
    loadCelebs();

    int score = 0;

    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

    int celebIndex = rand() % celebs.size();

    while(chrono::duration_cast<chrono::seconds>(end - start).count() < 30) {
        string input;
        string clue = celebs[celebIndex].getClue();
        string answer = celebs[celebIndex].getName();
        cout << clue << endl << "Enter your guess: ";
        getline(cin, input);
        if (input == answer) {
            cout << "Correct!" << endl;
            celebs.erase(celebs.begin() + celebIndex);
            celebIndex = rand() % celebs.size();
            score++;
        } else {
            cout << "Wrong!" << endl;
        }

        end = chrono::high_resolution_clock::now();

    }

    cout << "GAME OVER!" <<  endl;
    cout << "Your Score: " << score << endl;
    return 0;
}

void loadCelebs() {
    ifstream f("celebrities.txt");
    while(!f.eof()) {
        string name, clue;
        getline(f, name,':');
        getline(f, clue);
        celebs.push_back({name, clue});
    }
}