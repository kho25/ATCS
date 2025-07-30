#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    ifstream fin("reviews.txt");
    int num;
    string words;
    while (fin >> num) {
        getline(fin, words);
        stringstream ss(words);
        string word;
        while (ss >> word) {
            cout << word << " " << num << endl;
        }
    }

    return 0;
}
