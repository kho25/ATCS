#include <iostream>
#include <queue>
#include "shp_priority_queue.h"
using namespace std;

struct Student {
    string name;
    int grade;

    Student(string n, int g) {
        name = n;
        grade = g;
    }

     bool operator < (const Student & rhs) const {
        return this->grade < rhs.grade;
    }
};

int main() {
    cout << "Hello, World!" << endl;
    shp_priority_queue students;
    students.push("Brady");
    students.push("Ariv");
    students.push("Yuvi");
    students.push("James");

    while (!students.empty()) {
        cout << students.top() << endl;
        students.pop();
    }

    return 0;
}
