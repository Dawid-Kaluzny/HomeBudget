#ifndef DATE_H
#define DATE_H

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Date {
    bool isDateCorrect(string year, string month, string day);
    int calculateLastDayInMonth(string year, string month);
public:
    int getData();
};

#endif
