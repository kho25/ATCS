#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct RoomAssignment {
    string name;
    string num;
};

vector<RoomAssignment> assignments;

void loadRooms();
int getChoice();
void searchByRoom();
void searchByTeacher();

int main() {
    cout << "Welcome to the Campbell Room teacher database." << endl;
    loadRooms();

    while(true) {
        int choice = getChoice();
        if(choice == 1)
            searchByRoom();
        else if(choice == 2)
            searchByTeacher();
        else
            break;



    }

    cout << "Goodbye!" << endl;
    return 0;
}

void loadRooms() {
    ifstream f("rooms.txt");
    while(!f.eof()) {
        string number, who;
        f >> number;
        getline(f, who);
        who = who.substr(1);
        RoomAssignment ra;
        ra.name = who;
        ra.num = number;
        assignments.push_back(ra);
    }
    f.close();
}

int getChoice() {
    cout << "Choose an option:" << endl;
    cout << "1. Search by room." << endl;
    cout << "2. Search by teacher." << endl;
    cout << "3. Quit." << endl;
    while(true) {
        cout << "Your choice: ";
        int num;
        cin >> num;
        if(num>=1 && num<=3)
            return num;
    }
}

void searchByRoom() {
    cout << "Enter a room: ";
    string room;
    cin.ignore();
    cin >> room;

    for(int i = 0; i < assignments.size(); i++) {
        if(assignments[i].num == room) {
            cout << assignments[i].name << endl;
        }
    }

}

void searchByTeacher() {
    cout << "Enter a Teacher: ";
    string name;
    cin.ignore();
    getline(cin, name);

    for(int i = 0; i < assignments.size(); i++) {
        if(assignments[i].name == name) {
            cout << assignments[i].num << endl;
        }
    }
}
