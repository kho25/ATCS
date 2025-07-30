
#include <iostream>
#include "shplexicon.h"
using namespace std;

shplexicon::shplexicon() {
    root = nullptr;
}

shplexicon::~shplexicon() {
    freeHelper(root);
}

void shplexicon::freeHelper(shplexicon::Node *&tree) {
    if (tree == nullptr)
        return;
    for (int i=0; i<26; i++)
        freeHelper(tree->letters[i]);
    delete tree;
}

bool shplexicon::validate(string &word) const {
    for (int i=0; i<word.length(); i++)
        if (!isalpha(word[i]))
            return false;
        else
            word[i] = tolower(word[i]);
    return true;
}

int shplexicon::sizeHelper(shplexicon::Node *tree) const {
    if (tree == nullptr)
        return 0;
    else {
        int counter = 0;
        if (tree->isWord)
            counter++;
        for (int i=0; i<26; i++)
            counter += sizeHelper(tree->letters[i]);
        return counter;
    }
}

int shplexicon::size() const {
    return sizeHelper(root);
}

void shplexicon::insert(string word) {
    if (validate(word)) {
        insertHelper(root, word);
    }
}

void shplexicon::insertHelper(shplexicon::Node * & tree, string word) {
    if (tree == nullptr) {
        tree = new Node;
    }
    if (word == "")
        tree->isWord = true;
    else {
        int index = word[0] - 'a';
        insertHelper(tree->letters[index], word.substr(1));
    }
}

bool shplexicon::containsWord(string word) const {
    if (validate(word))
        return containsHelper(root, word);
    else
        return false;
}

bool shplexicon::containsHelper(shplexicon::Node *tree, string word) const {
    if (tree == nullptr)
        return false;
    else if (word == "")
        return tree->isWord;
    else {
        int index = word[0] - 'a';
        return containsHelper(tree->letters[index], word.substr(1));
    }
}

bool shplexicon::containsPrefixHelper(shplexicon::Node *tree, string word) const {
    if (tree == nullptr)
        return false;
    else if (word == "")
        return true;
    else {
        int index = word[0] - 'a';
        return containsPrefixHelper(tree->letters[index], word.substr(1));
    }
}

bool shplexicon::containsPrefix(string prefix) const {
    if (validate(prefix))
        return containsPrefixHelper(root, prefix);
    else
        return false;
}

void shplexicon::removeWord(string word) {
    if (validate(word))
        removeWordHelper(root, word);
}

void shplexicon::removeWordHelper(shplexicon::Node *&tree, string word) {
    if (tree == nullptr)
        return;
    else if (word == "")
        tree->isWord = false;
    else {
        int index = word[0] - 'a';
        removeWordHelper(tree->letters[index], word.substr(1));
    }

    for (int i=0; i<26; i++)
        if (tree->letters[i]!=nullptr)
            return;
    delete tree;
    tree = nullptr;
}

set<string> shplexicon::getWordsWithPrefix(string prefix) const {
    set<string> temp;
    getWordsWithPrefixHelper(getNode(prefix), temp, prefix);
    return temp;
}

void shplexicon::getWordsWithPrefixHelper(shplexicon::Node *tree, set<string> &words, string str) const {
    if (tree== nullptr || words.size() >= 50)
        return;
    else {
        if (tree->isWord)
            words.insert(str);
        for (int i=0; i<26; i++) {
            char ch = 'a' + i;
            //cout << ch << "..." << endl;
            getWordsWithPrefixHelper(tree->letters[i], words, str + ch);
        }
    }
}

shplexicon::Node* shplexicon::getNode(string str) const {
    return getNodeHelper(root, str);
}

shplexicon::Node* shplexicon::getNodeHelper(shplexicon::Node* tree, string str) const {
    if (tree == nullptr)
        return nullptr;
    else if (str == "")
        return tree;
    else {
        int index = str[0] - 'a';
        return getNodeHelper(tree->letters[index], str.substr(1));
    }
}
