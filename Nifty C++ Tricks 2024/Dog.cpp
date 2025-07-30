//
// Created by Kevin Morris on 11/16/22.
//

#include "Dog.h"

Dog::Dog(string name) {
    this->name = name;
}

string Dog::getName() const {
    return name;
}
string Dog::speak() const {
    return "woof";
}

