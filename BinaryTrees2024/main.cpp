#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    string value;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* makeStudentTree() {
    TreeNode *temp = new TreeNode;
    temp->value = "Katherine";
    temp->left = new TreeNode;
    temp->left->value = "Ariv";
    temp->right = new TreeNode;
    temp->right->value = "Peyton";
    temp->left->right = new TreeNode;
    temp->left->right->value = "Brady";
    temp->left->left = new TreeNode;
    temp->left->left->value = "Arhaan";
    temp->right->left = new TreeNode;
    temp->right->left->value = "Matthew";
    temp->right->right = new TreeNode;
    temp->right->right->value = "William";
    temp->left->left->right = new TreeNode;
    temp->left->left->right->value = "Ario";
    temp->left->left->left = new TreeNode;
    temp->left->left->left->value = "Adi";
    temp->left->right->right = new TreeNode;
    temp->left->right->right->value = "James";
    temp->right->left->left = new TreeNode;
    temp->right->left->left->value = "Kelly";
    temp->right->left->right = new TreeNode;
    temp->right->left->right->value = "Parsa";
    temp->right->right->left = new TreeNode;
    temp->right->right->left->value = "Sophie";
    temp->right->right->right = new TreeNode;
    temp->right->right->right->value = "Yuvi";
    return temp;
}

int size(TreeNode* tree) {
    if (tree == nullptr)
        return 0;
    else
        return 1 + size(tree->left) + size(tree->right);

}

int countLetters(TreeNode* tree) {
    if(tree == nullptr)
        return 0;
    else
        return tree->value.length() + countLetters(tree->left) + countLetters(tree->right);
}

bool allOddLength(TreeNode* tree) {
    if(tree==nullptr)
        return true;
    else if(tree->value.length() % 2 == 0)
        return false;
    else
        return allOddLength(tree->left) && allOddLength(tree->right);
}

bool contains(TreeNode* tree, string str) {
    if(tree==nullptr)
        return false;
    else if(tree->value == str)
        return true;
    else
        return contains(tree->left, str) || contains(tree->right, str);
}

bool containsBST(TreeNode* tree, string str) {
    if(tree == nullptr)
        return false;
    else if (tree->value == str)
        return true;
    else if (str > tree->value)
        return containsBST(tree-> right, str);
    else
        return containsBST(tree->left, str);
}

int height(TreeNode* tree) {
    if(tree == nullptr)
        return 0;
    else
        return 1 + max(height(tree->left), height(tree->right));
}

int isEqual(TreeNode* first, TreeNode* second) {
    if(first == nullptr && second == nullptr)
        return true;
    else if(first == nullptr | second == nullptr)
        return false;
    else
        return first->value == second-> value
            &&  isEqual(first->left, second->left)
             && (isEqual(first->right, second->right));
}

int countLeaves(TreeNode* tree) {
    if(tree == nullptr)
        return 0;
    else if(tree->left == nullptr && tree->right == nullptr)
        return 1;
    else
        return countLeaves(tree->left) + countLeaves(tree->right);
}

void getVectorHelper(TreeNode* tree, vector<string> &vec) {
    if(tree == nullptr)
        return;
    else {
        getVectorHelper(tree->left, vec);
        vec.push_back(tree->value);
        getVectorHelper(tree->right, vec);
    }

}

vector<string> getVector(TreeNode* tree) {
    vector<string> result;
    getVectorHelper(tree, result);
    return result;
}

void flip(TreeNode* tree) {
    if(tree == nullptr)
        return;
    else {
        TreeNode* temp = tree->left;
        tree->left = tree->right;
        tree->right = temp;

        flip(tree->right);
        flip(tree->left);
    }
}

void removeLeaves(TreeNode* &tree) {
    if(tree == nullptr)
        return;
    else if(tree->left == nullptr && tree->right == nullptr){
        delete tree;
        tree = nullptr;
    }
    else{
        removeLeaves(tree->left);
        removeLeaves(tree->right);
    }
}


int main() {
    cout << "Hello, Binary Trees!" << endl;
    TreeNode *root = makeStudentTree();
    cout << size(root) << endl;
    cout << countLetters(root) << endl;
    if(allOddLength(root))
        cout << "All odd" << endl;
    else
        cout << "Not all odd" << endl;

    if(contains(root, "Kelly"))
        cout << "Kelly is in the tree" << endl;
    if(contains(root, "Neal"))
        cout << "Neal is in the tree" << endl;

    if(containsBST(root, "Parsa"))
        cout << "Parsa is in the tree" << endl;

    cout << height(root) << endl;

    if(isEqual(root, root)) {
        cout << "EQUAL" << endl;
    }

    cout << "There are " << countLeaves(root) << " leaves" << endl;

    vector<string> vec = getVector(root);
    for(string str : vec)
        cout << str << endl;

    return 0;
}
