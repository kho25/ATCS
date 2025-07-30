
#ifndef HUFFMAN_YOUR_HUFFMAN_CODE_H
#define HUFFMAN_YOUR_HUFFMAN_CODE_H

#include <map>
#include "huffman_helper.h"
using namespace std;

struct TreeNode {
    char ch;
    int weight;
    TreeNode *left;
    TreeNode *right;

    TreeNode(char cha) {
        ch = cha;
        left == nullptr;
        right == nullptr;
    }
    TreeNode() {
        left == nullptr;
        right == nullptr;
    }
};
struct CompareTreeNode
{
    bool operator()(const TreeNode* lhs, const TreeNode* rhs) const
    {
        return lhs->weight > rhs->weight;
    }
};
/* You need the unusual CompareTreeNode struct above if you want to make
 * a priority queue of TreeNodes.  (Hint: You do!)  This struct defines an
 * operator for comparing TreeNode*, which makes it possible for the
 * underlying heap for a priority queue to work correctly.  It's weird,
 * but here's the syntax you'll need:
       priority_queue<TreeNode*, vector<TreeNode*>, CompareTreeNode> pq;
 * The first parameter describes what it is a priority queue of, the
 * second parameter describes the underlying heap implementation ("I'm
 * using a vector for this heap"), and the third parameter specifies a
 * way to compare TreeNode*.  Phew...
 */

// NOTE: The struct EncodedData is defined in the huffman_helper.h file
void destroyTree(TreeNode* tree) {
    if (tree->left == nullptr && tree->right == nullptr)
        return;
    destroyTree(tree->left);
    destroyTree(tree->right);
    delete tree;
}
map<char, int> makeFreqMap(const string &text) {
    map<char, int> result;
    for(char ch : text) {
        result[ch]++;
    }

    return result;
}
priority_queue<TreeNode*, vector<TreeNode*>, CompareTreeNode> makeQueue(map<char,int> freqMap) {
    priority_queue<TreeNode*, vector<TreeNode*>, CompareTreeNode> result;

    for(auto i : freqMap) {
        TreeNode* tree = new TreeNode();
        tree->ch = i.first;
        tree->weight = i.second;
        // cout << tree->ch << ": " << tree->weight << endl;
        result.push(tree);
    }

    return result;
}

priority_queue<TreeNode*, vector<TreeNode*>, CompareTreeNode> huffmanEncode(priority_queue<TreeNode*, vector<TreeNode*>, CompareTreeNode> pq) {
    while(pq.size() > 1) {
        TreeNode* tree = new TreeNode();
        tree->left = pq.top();
        pq.pop();
        tree->right = pq.top();
        pq.pop();

        tree->weight = tree->left->weight + tree->right->weight;
        pq.push(tree);
    }
    return pq;
}

map<char, queue<Bit>> makeEncodingMap(TreeNode* tree, queue<Bit> &code, map<char, queue<Bit>> &result) {
    if(tree->left == nullptr && tree->right == nullptr) {
        result[tree->ch] = code;
    }
    else {
        queue<Bit> qL = code;
        qL.push(0);
        makeEncodingMap(tree->left, qL, result);
        queue<Bit> qR = code;
        qR.push(1);
        makeEncodingMap(tree->right, qR, result);
    }
    return result;
}

queue<Bit> encodeFile(map<char, queue<Bit>> encodingMap, string &text) {
    queue<Bit> result;
    for(char i : text) {
        queue<Bit> code = encodingMap.at(i);
        while(!code.empty()) {
            result.push(code.front());
            code.pop();
        }
    }
    return result;
}
void flattenTree(queue<Bit> &encodedTreeShape, queue<char> &encodedTreeLeaves, TreeNode* tree){
    if(tree->left == nullptr && tree->right == nullptr) {
        encodedTreeShape.push(0);
        encodedTreeLeaves.push(tree->ch);
    }
    else{
        encodedTreeShape.push(1);
        flattenTree(encodedTreeShape, encodedTreeLeaves, tree->left);
        flattenTree(encodedTreeShape, encodedTreeLeaves, tree->right);
    }

}

EncodedData compress(string text) {
    EncodedData result;
    // you've got a lot to write here
    map<char, int> freqMap = makeFreqMap(text);

    priority_queue<TreeNode*, vector<TreeNode*>, CompareTreeNode> pq = makeQueue(freqMap);
    pq = huffmanEncode(pq);

    TreeNode* tree = pq.top();
    queue<Bit> q;
    map<char, queue<Bit>> encodingMap;
    encodingMap = makeEncodingMap(tree, q, encodingMap);

    queue<Bit> encodedMessageBits = encodeFile(encodingMap, text);

    queue<Bit> encodedTreeShape;
    queue<char> encodedTreeLeaves;
    flattenTree(encodedTreeShape, encodedTreeLeaves, tree);

    result.messageBits = encodedMessageBits;
    result.treeLeaves = encodedTreeLeaves;
    result.treeShape = encodedTreeShape;

    destroyTree(tree);

    return result;
}

TreeNode* makeTree(queue<Bit> &treeShape, queue<char> &treeLeaves) {
    Bit bit = treeShape.front();
    treeShape.pop();

    if(bit == 0) {
        TreeNode* tree = new TreeNode();
        tree->ch = treeLeaves.front();
        treeLeaves.pop();
        return tree;
    }
    else {
        TreeNode* tree = new TreeNode();
        tree->left = makeTree(treeShape, treeLeaves);
        tree->right = makeTree(treeShape, treeLeaves);
        return tree;
    }
}


string decodeCharacter(queue<Bit> &messageBits, TreeNode* head) {
    string result = "";

    if(head->left == nullptr && head->right == nullptr) {
        string a;
        a.push_back(head->ch);
        return a;
    }
    Bit bit = messageBits.front();
    messageBits.pop();
    if(bit == 0) {
        return result + decodeCharacter(messageBits, head->left);
    }
    else {
        return result + decodeCharacter(messageBits, head->right);

    }

}

string decompress(EncodedData& data) {
    TreeNode* tree = makeTree(data.treeShape, data.treeLeaves);
    string result;

    while(!data.messageBits.empty()) {
        result += decodeCharacter(data.messageBits, tree);
    }
    destroyTree(tree);

    return result;
}

#endif //HUFFMAN_YOUR_HUFFMAN_CODE_H
