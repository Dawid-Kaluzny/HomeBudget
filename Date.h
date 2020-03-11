#ifndef DATE_H
#define DATE_H

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "AuxiliaryMethods.h"

using namespace std;

class Date {
    static bool isDateCorrect(string year, string month, string day);
public:
    static int getData();
    static string convertDateFromIntToFormattedString(int date);
    static int convertDateFromFormattedStringToInt(string formattedString);
    static int calculateLastDayInMonth(string year, string month);
};

#endif
