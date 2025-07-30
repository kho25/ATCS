//
// Created by Kelly Ho on 9/1/24.
//

#include "Celebrity.h"

#include <iostream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;

Celebrity::Celebrity(string n, string c) {
    name = n;
    clues = sepClues(c);
}

string Celebrity::getName() {
    return name;
}

string Celebrity::getClue() {
    if(clues.size() == 0) {
        return "no more clues";
    }

    int index = rand() % clues.size();
    string clue = clues.at(index);
    clues.erase(clues.begin()+index);
    return clue;
}

vector<string> Celebrity::sepClues(string c) {
    vector<string> result;
    int start = 0;
    for(int i = 0; i < c.size(); i++) {
        if(c.at(i) == ',') {
            string subClue = c.substr(start, i-start);
            result.push_back(subClue);
            start = i+1;
        }

    }
    result.push_back(c.substr(start));
    return result;
}


Celebrity::~Celebrity() {

}
