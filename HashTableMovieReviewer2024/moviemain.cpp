#include <iostream>
#include <fstream>
#include <sstream>

#include "shphashtable.h"

using namespace std;

void readInFile(string filename, shphashtable &reviews) {
    ifstream fin(filename);
    int num;
    string words;
    while (fin >> num) {
        getline(fin, words);
        stringstream ss(words);
        string word;
        while (ss >> word) {
            // cout << word << " " << num << endl;
            reviews.put(word , num);
        }
    }
}

void evalReview(string review, const shphashtable &reviews) {
    int numWords = 0;
    double totalRating = 0;

    stringstream ss(review);
    string word;
    while (ss >> word){
        double rating = reviews.getAverage(word);
        if(!(rating >= 1.8 && rating <= 2.1)) {
            totalRating += rating;
            numWords++;
        }
    }

    double finalRating = totalRating/numWords;
    if(numWords == 0)
        finalRating = 2;
    cout << "Your Rating = " << finalRating << endl;
}

int main() {
    cout << "Hello, Movie Reviews!" << endl;
    shphashtable reviews(20003);
    // load review data here, probably in a function
    readInFile("reviews.txt", reviews);

    reviews.printStats();

    // prompt user for new review, parse it, output predicted rating
    string input = "y";
    while(input =="y") {
        cout << endl << "Write your review... ";
        string review;
        getline(cin, review);
        evalReview(review, reviews);

        cout << "Do you want to write another review? ";
        getline(cin, input);
    }
    return 0;
}