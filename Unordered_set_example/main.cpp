#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main() {
    cout << "Hello, Sets!" << endl << endl;

    cout << "..........SETS.........." << endl;
    set<string> students;
    students.insert("Ariv");
    students.insert("Sophie");
    students.insert("Peyton");
    students.insert("Arhaan");
    students.insert("Ario");
    students.insert("Kelly");
    students.insert("Parsa");
    students.insert("Matthew");
    students.insert("Adi");
    students.insert("Brady");
    students.insert("James");
    students.insert("William");
    students.insert("Yuvi");
    students.insert("Katherine");
    for (auto itr = students.begin();itr != students.end(); itr++) {
        cout << *itr << endl;
    }
    cout << endl << "..........UNORDERED.SETS.........." << endl;
    unordered_set<string> names;
    names.insert("Ariv");
    names.insert("Sophie");
    names.insert("Peyton");
    names.insert("Arhaan");
    names.insert("Ario");
    names.insert("Kelly");
    names.insert("Parsa");
    names.insert("Matthew");
    names.insert("Adi");
    names.insert("Brady");
    names.insert("James");
    names.insert("William");
    names.insert("Yuvi");
    names.insert("Katherine");
    for (auto itr = names.begin();itr != names.end(); itr++) {
        cout << *itr << endl;
    }
    cout << "NUM BUCKETS = " << names.bucket_count() << endl;
    for (int i=0; i<names.bucket_count(); i++) {
        cout << i << ": " << names.bucket_size(i) << endl;
    }
    auto shphash = names.hash_function();

    cout << "Matthew hashes to " << shphash("Matthew") << endl;
    cout << "Matthew --> " << shphash("Matthew") % names.bucket_count() << endl;
    cout << "Adi --> " << shphash("Adi") % names.bucket_count() << endl;
    return 0;
}