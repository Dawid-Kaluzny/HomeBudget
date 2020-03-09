#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class AuxiliaryMethods {
public:
    static string changeFirstLetterToUpperRemainingToLower(string text);
    static char loadCharacter();
    static string convertIntToString(int digital);
    static string convertFloatToString(float digitalFloat);
};

#endif
