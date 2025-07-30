
#include "LoudDog.h"

LoudDog::LoudDog(string name) : Dog(name) {
}

string LoudDog::speak() const {
    return Dog::speak() + " " + Dog::speak();
}
