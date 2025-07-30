#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct TreeNode {
    string value;
    TreeNode *left; //yes
    TreeNode *right; //no
    TreeNode(string val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
    TreeNode() {
        left = nullptr;
        right = nullptr;
    }
};

void makeCityTree(TreeNode* &current, ifstream &f) {
    string text;
    getline(f, text);
    current = new TreeNode(text.substr(1));

    if(text[0] == 'Q') {
        makeCityTree(current->left, f);
        makeCityTree(current->right, f);
    }
}

void saveFile(TreeNode* current, ofstream &f) {
    if(current->right == nullptr && current->left == nullptr) {
        f << "A"+current->value << endl;
    }
    else {
        f << "Q"+current->value << endl;
        saveFile(current->left, f);
        saveFile(current->right, f);
    }
}

void endGame(TreeNode* root) {
    cout << "Do you want to save the current city information to a file? ";
    string answer;
    getline(cin, answer);

    if(answer == "y"){
        string filename;
        cout << "Enter name of file (duplicate files will be overwritten): ";
        getline(cin, filename);
        ofstream fout(filename);
        fout.clear();
        saveFile(root, fout);
    }
}

void makeNewCity(TreeNode* root) {
    string city, question, answer;
    cout << endl << "Darn. What was your city? ";
    getline(cin, city);
    cout << "Please enter a question that would distinguish between " << root->value << " and " << city << "." << endl;
    cout << "Enter question: ";
    getline(cin, question);
    cout << "If you were thinking of " << city << " what would the answer to your question be? ";
    getline(cin, answer);

    string ogcity = root->value;

    root->value = question;
    if(answer == "y") {
        root->left = new TreeNode(city);
        root->right = new TreeNode(ogcity);
    }
    else {
        root->left = new TreeNode(ogcity);
        root->right = new TreeNode(city);
    }

}

void newGame(TreeNode* root){
    cout << endl << "Think of a city. Please press return when you are ready to begin..." << endl;
    string input;
    getline(cin, input);

    TreeNode* temp = root;
    while(!(temp->left == nullptr && temp->right == nullptr)) {
        cout << temp->value << " ";
        string answer;
        getline(cin, answer);
        if(answer == "y")
            temp = temp->left;
        else
            temp = temp->right;
    }
    cout << "Is it " << temp->value << "? ";
    string answer;
    getline(cin, answer);

    if(answer == "y")
        cout << "Yes! I guessed your city correctly! " << endl;
    else {
        makeNewCity(temp);
    }

    cout << endl << "Do you want to play again? ";
    getline(cin, answer);
    if(answer == "y")
        newGame(root);
    else
        endGame(root);

}

int main() {
    cout << "City Guessing Game" << endl << endl;
    cout << "Welcome to the city City Guessing Game!" << endl;
    string filename;
    cout << "Enter the name of the data file: ";
    getline(cin, filename);
    TreeNode* root = nullptr;
    ifstream fin(filename);

    makeCityTree(root, fin);
    newGame(root);

    cout << "Good bye!" << endl;

    return 0;
}