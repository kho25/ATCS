#include <iostream>
#include <stack>
using namespace std;

struct EComponent {
    string op;
    int number;
};

struct ETNode {
    ETNode *left, *right;
    EComponent value;
    ETNode(string oper) {
        value.op = oper;
        left = nullptr;
        right = nullptr;
    }
    ETNode(int num) {
        value.op = "#";
        value.number = num;
        left = nullptr;
        right = nullptr;
    }
    string tostring() {
        if (value.op != "#")
            return value.op;
        else
            return to_string(value.number);
    }
};

ETNode *buildExpressionTree() {
    ETNode *tree = new ETNode("*");
    tree->left = new ETNode("+");
    tree->left->left = new ETNode(2);
    tree->left->right = new ETNode(1);
    tree->right = new ETNode("-");
    tree->right->left = new ETNode("/");
    tree->right->left->left = new ETNode(60);
    tree->right->left->right = new ETNode(4);
    tree->right->right = new ETNode(6);
    return tree;
}

void printInOrder(ETNode* tree) {
    if(tree!=nullptr){
        printInOrder(tree->left);
        cout << tree->tostring() << " ";
        printInOrder(tree->right);
    }
}

void printPostOrder(ETNode* tree) {
    if(tree!=nullptr){
        printPostOrder(tree->left);
        printPostOrder(tree->right);
        cout << tree->tostring() << " ";
    }
}

void evaluate(ETNode* tree) {
    if(tree == nullptr || tree->value.op == "#")
        return;
    evaluate(tree->left);
    evaluate(tree->right);
    int left = tree->left->value.number;
    int right = tree->right->value.number;
    delete tree->left;
    delete tree->right;
    tree->left = nullptr;
    tree->right = nullptr;

    if(tree->value.op == "*")
        tree->value.number = left * right;
    else if(tree->value.op == "+")
        tree->value.number = left + right;
    else if(tree->value.op == "/")
        tree->value.number = left / right;
    else if(tree->value.op == "-")
        tree->value.number = left - right;
    tree->value.op = "#";

}
int main() {
    cout << "Hello, Expression Tree!" << endl;
    ETNode *root = buildExpressionTree();
    printInOrder(root);
    cout << endl;
    printPostOrder(root);
    cout << endl;
    evaluate(root);
    cout << root->tostring()<< endl;

    return 0;
}