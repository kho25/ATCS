
#include "WordEntry.h"
using namespace std;

WordEntry::WordEntry() {
    word = "";
    totalStars = 0;
    totalRatings = 0;
}

WordEntry::WordEntry(string str, int score) {
    word = str;
    totalStars = score;
    totalRatings = 1;
}

string WordEntry::getWord() const {
    return word;
}

double WordEntry::getAvgScore() const {
    return 1.0*totalStars/totalRatings;
}

void WordEntry::addScore(int score) {
    totalStars += score;
    totalRatings++;
}
