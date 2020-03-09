#ifndef FINANCE_H
#define FINANCE_H

#include <cstdlib>
#include <iostream>

using namespace std;

class Finance {
    int userId;
    int date;
    string item;
    float amount;

public:
    Finance(int userId = 0, int date = 0, string item = "", float amount = 0.0) {
        this -> userId = userId;
        this -> date = date;
        this -> item = item;
        this -> amount = amount;
    }
    bool operator < (const Finance& order) const {
        return (date < order.date);
    }
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(float amount);
    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
    float enterFinanceAmount();
};

#endif
