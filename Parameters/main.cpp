#include <iostream>

using namespace std;

// str was "PASSED BY VALUE" (str is a COPY)
int countSpaces(string str) {
    int counter = 0;
    for (int i=0; i<str.length(); i++) {
        if (str[i]==' ')
            counter++;
    }
    str = "whatever";
    return counter;
}

// str was "PASSED BY REFERENCE" (str is a reference to the actual parameter)
void changeSpaces(string &str, char ch) {
    for (int i=0; i<str.length(); i++) {
        if (str[i]==' ')
            str[i] = ch;
    }
}
// str was "PASSED BY CONSTANT REFERENCE" (str is a reference, but you can't change it)
// why?  the parameter is big, so this is faster
int countLetter(const string &str, char ch) {
    int counter = 0;
    for (int i=0; i<str.length(); i++) {
        if (str[i]==ch)
            counter++;
    }
    return counter;
}


int main() {
    cout << "Hello, World!" << endl;
    string phrase = "Advanced Topics in Computer Science Honors";
    int spaces = countSpaces(phrase);
    cout << spaces << endl;
    changeSpaces(phrase, '-');
    cout << phrase << endl;

    int num = countLetter(phrase, 'e');
    cout << num << endl;
    return 0;
}

