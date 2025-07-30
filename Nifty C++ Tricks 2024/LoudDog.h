//
// Created by Kevin Morris on 11/16/22.
//

#include <iostream>
#include "Dog.h"

#ifndef NIFTY_C___TRICKS_2022_LOUDDOG_H
#define NIFTY_C___TRICKS_2022_LOUDDOG_H

using namespace std;

class LoudDog:public Dog {
public:
    LoudDog(string name);
    string speak() const;
private:
};


#endif //NIFTY_C___TRICKS_2022_LOUDDOG_H
