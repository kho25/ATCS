

#ifndef SHPLEXICON_SHPLEXICON_H
#define SHPLEXICON_SHPLEXICON_H
#include <string>
#include <map>
#include <set>

using namespace std;

class shplexicon {
public:
    shplexicon();
    ~shplexicon();

    int size() const;
    void insert(string word);
    bool containsWord(string word) const;
    bool containsPrefix(string prefix) const;
    void removeWord(string word);
    set<string> getWordsWithPrefix(string prefix) const;

private:
    struct Node {
        Node* letters[26];
        bool isWord;
        Node() {
            isWord = false;
        }
    };
    Node *root;

    Node* getNode(string str) const;
    Node* getNodeHelper(Node* tree, string str) const;
    bool validate(string & word) const;
    void insertHelper(Node * & tree, string word);
    bool containsHelper(Node * tree, string word) const;
    bool containsPrefixHelper(Node * tree, string word) const;
    int sizeHelper(Node *tree) const;
    void freeHelper(Node * & tree);
    void removeWordHelper(Node * &tree, string word);
    void getWordsWithPrefixHelper(Node *tree, set<string> & words, string str) const;

};


#endif //SHPLEXICON_SHPLEXICON_H
