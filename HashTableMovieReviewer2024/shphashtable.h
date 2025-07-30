

#ifndef HASHTABLEMOVIEREVIEWER_SHPHASHTABLE_H
#define HASHTABLEMOVIEREVIEWER_SHPHASHTABLE_H
#include <string>

#include "WordEntry.h"
using namespace std;

class shphashtable {

public:
    shphashtable(int numBuckets);
    ~shphashtable();
    bool contains(string str) const;
    void put(string str, int score);
    void printStats() const;
    double getAverage(string word) const;

private:
    struct Node {
        WordEntry value;
        Node* next;
    };
    Node** buckets;

    int size;

    //private functions
    int getHashCode(string str) const;
    Node* getPointer(string str) const;

};


#endif //HASHTABLEMOVIEREVIEWER_SHPHASHTABLE_H
