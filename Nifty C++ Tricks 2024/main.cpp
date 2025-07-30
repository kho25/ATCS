#include <iostream>
#include <vector>
#include <limits>
#include <thread>
#include <algorithm>
#include <chrono>
#include "LoudDog.h"

using namespace std;

void showZeroIsFalse();
void showTernary();
void showBitwise();
void showUnsigned();
void showPlusPlus();
void showContinue();
void showDefaultParameters();
void showInheritance();
void showLambda();
void showThreads();
void showPoundDefine();

int main() {
    cout << "Nifty C++ Tricks" << endl;
    int choice;
    while (choice != 0 && choice != 12) {
        cout << endl;
        cout << "1) zero is false" << endl;
        cout << "2) ternary operator" << endl;
        cout << "3) bitwise and/or" << endl;
        cout << "4) short, long, unsigned" << endl;
        cout << "5) i++ vs ++i" << endl;
        cout << "6) continue" << endl;
        cout << "7) default parameters" << endl;
        cout << "8) inheritance" << endl;
        cout << "9) lambda functions" << endl;
        cout << "10) threads" << endl;
        cout << "11) #define" << endl;
        cout << "12) QUIT" << endl;

        choice = -1;
        while (choice < 0 || choice > 12) {
            cout << "Enter your choice: ";
            cin >> choice;
        }
        cin.ignore();
        cout << endl;
        if (choice == 1)
            showZeroIsFalse();
        else if (choice == 2)
            showTernary();
        else if (choice == 3)
            showBitwise();
        else if (choice == 4)
            showUnsigned();
        else if (choice == 5)
            showPlusPlus();
        else if (choice == 6)
            showContinue();
        else if (choice == 7)
            showDefaultParameters();
        else if (choice == 8)
            showInheritance();
        else if (choice == 9)
            showLambda();
        else if (choice == 10)
            showThreads();
        else if (choice == 11)
            showPoundDefine();
        else // if (choice == 12)
            break;
    }
    cout << "Have a nice day!" << endl;
    return 0;
}
void showZeroIsFalse() {
    int num;
    cout << "Please enter a number: ";
    cin >> num;
    while (num) {
        cout << "Good job!  Please enter another number: ";
        cin >> num;
    }
    cout << "Thanks!" << endl << endl;
}

void showTernary() {
    int numPonies;
    cout << "How many ponies do you have? ";
    cin >> numPonies;
    cout << "You have " << numPonies << " " << (numPonies==1 ? "pony" : "ponies") << "." << endl << endl;
}
void showBitwise() {
    int x = 25; // 11001 in binary
    int y = 20; // 10100 in binary
    cout << "25 bitwise and 20 is " << (x & y) << endl;
    cout << "25 bitwise or 20 IS " << (x | y) << endl;
}
void showUnsigned() {
    int a = 27;
    short b = 27;
    long c = 27;
    unsigned int d = 27;
    unsigned short e = 27;
    unsigned long f = 27;

    cout << "a is " << sizeof(a) << " bytes." << endl;
    cout << "b is " << sizeof(b) << " bytes." << endl;
    cout << "c is " << sizeof(c) << " bytes." << endl;
    cout << "d is " << sizeof(d) << " bytes." << endl;
    cout << "e is " << sizeof(e) << " bytes." << endl;
    cout << "f is " << sizeof(f) << " bytes." << endl;
    cout << endl;
    cout << "a's range is [" << numeric_limits<int>::min() << "," << numeric_limits<int>::max() << "]." << endl;
    cout << "b's range is [" << numeric_limits<short>::min() << "," << numeric_limits<short>::max() << "]." << endl;
    cout << "c's range is [" << numeric_limits<long>::min() << "," << numeric_limits<long>::max() << "]." << endl;
    cout << "d's range is [" << numeric_limits<unsigned int>::min() << "," << numeric_limits<unsigned int>::max() << "]." << endl;
    cout << "e's range is [" << numeric_limits<unsigned short>::min() << "," << numeric_limits<unsigned short>::max() << "]." << endl;
    cout << "f's range is [" << numeric_limits<unsigned long>::min() << "," << numeric_limits<unsigned long>::max() << "]." << endl;

}

void showPlusPlus() {
    int score = 10;
    cout << "Your score is " << score << "." << endl;
    cout << "Your score is " << score++ << "." << endl;
    cout << "Your score is " << score << "." << endl;
    cout << "Your score is " << ++score << "." << endl;
    cout << "Your score is " << score << "." << endl;

}
void showContinue() {
    vector<int> nums;
    // 100 random numbers in the range [0,999]
    for (int i=0; i<100; i++) {
        nums.push_back(rand() % 1000);
    }

    int count7 = 0;
    int count11 = 0;
    for (int i=0; i<nums.size(); i++) {
        if (nums[i]<100)
            continue;
        if (nums[i] % 7 == 0)
            count7++;
        if (nums[i] % 11 == 0)
            count11++;
    }
    cout << "Ignoring numbers less than 100, there are " <<
            count7 << " multiples of seven and " <<
            count11 << " multiples of eleven." << endl;
}

int count(vector<int> vec, int val = 27) {
    int counter = 0;
    for (int num : vec)
        if (num == val)
            counter++;
    return counter;
}

void showDefaultParameters() {
    vector<int> nums;
    // 1000 random numbers in the range [0,99]
    for (int i=0; i<1000; i++) {
        nums.push_back(rand() % 100);
    }
    cout << "There are " << count(nums, 50) << " 50's in the vector." << endl;
    cout << "There are " << count(nums) << " 27's in the vector." << endl;
}

void showInheritance() {
    Dog dog1("Snoopy");
    LoudDog dog2("Clifford");

    cout << dog1.getName() << " says " << dog1.speak() << "." << endl;
    cout << dog2.getName() << " says " << dog2.speak() << "." << endl;
}
void printMe(int num) {
    cout << num << " ";
}
void printMeIfEven(int num) {
    if (num % 2 == 0)
        cout << num << " ";
}

int squareMe(int num) {
    return num * num;
}

void showLambda() {
    int nums[] = {2, 3, 4, 5, 7, 10};
    vector<int> vec(begin(nums), end(nums));

    for_each(vec.begin(), vec.end(), printMe);
    cout << endl;

    for_each(vec.begin(), vec.end(), printMeIfEven);
    cout << endl;

    vector<int> result;
    transform(vec.begin(), vec.end(), back_inserter(result), squareMe);

    for_each(result.begin(), result.end(), printMe);
    cout << endl;

    vector<int> anotherResult;
    transform(vec.begin(), vec.end(), back_inserter(anotherResult), [](int num) {return 2*num;});

    for_each(anotherResult.begin(), anotherResult.end(), printMe);
    cout << endl;
}
void doSomethingWithEvens() {
    vector<int> evens;
    for (int i=2; i<=20; i+=2)
        evens.push_back(i);
    for (int num : evens) {
        cout << num << "...";
        chrono::milliseconds pauseTime(rand()%10);
        this_thread::sleep_for(pauseTime);
    }
}

void doSomethingWithOdds() {
    vector<int> odds;
    for (int i=1; i<=19; i+=2)
        odds.push_back(i);
    for (int num : odds) {
        cout << num << "...";
        chrono::milliseconds pauseTime(rand()%10);
        this_thread::sleep_for(pauseTime);
    }
}

void showThreads() {
    thread first(doSomethingWithEvens);
    thread second(doSomethingWithOdds);

    first.join();
    second.join();
    cout << endl;
}
#define NUMCOOKIES 45
#define cccooouuuttt cout
#define ForLoop(x) for (int i=0; i<x; i++)

void showPoundDefine() {
    int numCookies = NUMCOOKIES;
    numCookies += 5;
    cout << "You have " << numCookies << " cookies." << endl;
    cccooouuuttt << "Wow!  That's a lot of cookies!" << endl;
    ForLoop(10) {cout << "mmmmmm....." << endl;}
}
