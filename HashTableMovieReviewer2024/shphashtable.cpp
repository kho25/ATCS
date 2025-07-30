

#include "shphashtable.h"
#include <string>
#include <iostream>

using namespace std;

shphashtable::shphashtable(int numBuckets) {
    size = numBuckets;
    buckets = new Node*[size]; //array of pointers that will become a linked list or nullptr

    for(int i = 0; i<numBuckets; i++)
        buckets[i] = nullptr;
}

shphashtable::~shphashtable() {
    for(int i = 0; i < size; i++) {
        while(buckets[i] != nullptr) {
            Node* save = buckets[i];
            buckets[i] = buckets[i]->next;
            delete save;
        }
    }
    delete[] buckets;
}

bool shphashtable::contains(string str) const{
    return getPointer(str) != nullptr;
}

void shphashtable::put(string str, int score) {
    if(!contains(str)) {
        int index = getHashCode(str);
        Node* head = buckets[index];
        Node* temp = new Node;
        temp->value = WordEntry(str, score);
        temp->next = head;
        buckets[index] = temp;
    }
    else {
        Node* temp = getPointer(str);
        temp->value.addScore(score);
    }
}

void shphashtable::printStats() const {
    int numBuckets = size;
    int numWords = 0;
    int numEmptyBuckets = 0;
    int longestChain = 0;
    int totalWordRating = 0;

    for(int i = 0; i < size; i++) {
        Node* temp = buckets[i];
        int chainLen = 0;
        while(temp != nullptr) {
            chainLen++;
            numWords++;
            totalWordRating += temp->value.getAvgScore();
            temp = temp->next;
        }
        if(chainLen > longestChain)
            longestChain = chainLen;
        if(buckets[i] == nullptr)
            numEmptyBuckets++;
    }

    double avgChainLen = 1.0*numWords/(numBuckets-numEmptyBuckets);

    cout << "STATS" << endl;
    cout << "NUM BUCKETS: " << numBuckets << endl;
    cout << "NUM WORDS: " << numWords << endl;
    cout << "NUM EMPTY BUCKETS: " << numEmptyBuckets << endl;
    cout << "LONGEST CHAIN: " << longestChain << endl;
    cout << "AVG CHAIN LEN: " << avgChainLen << endl;
    cout << "AVG WORD SCORE: " << 1.0*totalWordRating/numWords << endl;

}

double shphashtable::getAverage(string word) const{
    Node* head = getPointer(word);
    if(head == nullptr)
        return 2.0;
    return head->value.getAvgScore();

}

int shphashtable::getHashCode(string str) const {
    hash<string> hashFunc;
    return hashFunc(str)%size;
}

shphashtable::Node* shphashtable::getPointer(string str) const {
    int index = getHashCode(str);
    Node* head = buckets[index];
    Node* temp = head;
    while(temp != nullptr) {
        if(temp->value.getWord() == str)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}
