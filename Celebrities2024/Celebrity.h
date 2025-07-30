//
// Created by Kelly Ho on 9/1/24.
//

#ifndef CELEBRITY_H
#define CELEBRITY_H
#include <string>
#include <vector>

using namespace std;

class Celebrity {
    public:
        Celebrity(string name, string clues);
        string getName();
        string getClue();
        ~Celebrity();
    private:
        string name;
        vector<string> clues;
        vector<string> sepClues(string clues);

};



#endif //CELEBRITY_H
