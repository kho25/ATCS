#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

void testLetterFrequency() {
    ifstream f("file.txt");

    map<char, int> freqMap;
    char ch;
    while(f >> ch) {
        ch = toupper(ch);
        freqMap[ch]++;
    }

    for(auto iter = freqMap.begin(); iter != freqMap.end(); iter++) {
        cout << iter->first << ": " << iter->second << endl;
    }
}

bool checkBalance(string str) {
    stack<char> s;
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if(ch == '(' || ch == '{')
            s.push(ch);
        else if(ch == ')') {
            if(s.empty() || s.top() != '(')
                return false;
            s.pop();
        }
        else if(ch == '}') {
            if(s.empty() || s.top() != '{')
                return false;
            s.pop();
        }
    }
    return s.empty();
}

void testCheckBalance() {
    if(checkBalance("if (num<0) {x=3;} else {y=4;}"))
        cout << "It balances" << endl;
    else
        cout << "It doesn't balance" << endl;
}

template <typename ElemType>
set<ElemType> setIntersection(set<ElemType> a, set<ElemType> b) {
    set<ElemType> result;

    for(ElemType x: a) {
       if(b.find(x) != b.end()) {
           result.insert(x);
       }
    }

    return result;
}

void testSetIntersection() {
    set<int> a, b;
    for(int i = 1; i <=5; i++) {
        a.insert(i);
    }
    for(int i = 3; i <= 10; i++) {
        b.insert(i);
    }

    set<int> c = setIntersection(a,b);

    for(int num : c) {
        cout << num << endl;
    }
}

void testFriends() {
    map<string, set<string>> friends;
    cin.ignore();
    string line;
    getline(cin, line);
    while(!line.empty()) {
        int index = line.find(" ");
        string a = line.substr(0,index);
        string b = line.substr(index+1);
        friends[a].insert(b);
        friends[b].insert(a);
        getline(cin, line);
    }
    for(auto iter = friends.begin(); iter != friends.end(); iter++) {
        cout << iter->first << ": ";
        set<string> value = iter->second;
        for(string name: value) {
            cout << name << " ";
        }
        cout << endl;
    }

}
int main() {
    cout << "Hooray for ADTs!" << endl;
    cout << "Choice? ";
    int choice;
    cin >> choice;
    if (choice == 0)
        testLetterFrequency();
    else if (choice == 1)
        testCheckBalance();
    else if (choice == 2)
        testSetIntersection();
    else if (choice == 3)
        testFriends();
    return 0;
}