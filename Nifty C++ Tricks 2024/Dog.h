//
// Created by Kevin Morris on 11/16/22.
//
#include <iostream>

#ifndef NIFTY_C___TRICKS_2022_DOG_H
#define NIFTY_C___TRICKS_2022_DOG_H

using namespace std;

class Dog {
public:
    Dog(string name);
    string getName() const;
    string speak() const;
private:
    string name;
};


#endif //NIFTY_C___TRICKS_2022_DOG_H
