#include "Finance.h"

void Finance::setUserId(int userId) {
    this -> userId = userId;
}

void Finance::setDate(int date) {
    this -> date = date;
}

void Finance::setItem(string item) {
    this -> item = item;
}

void Finance::setAmount(float amount) {
    this -> amount = amount;
}

int Finance::getUserId() {
    return userId;
}

int Finance::getDate() {
    return date;
}

string Finance::getItem() {
    return item;
}

float Finance::getAmount() {
    return amount;
}

float Finance::enterFinanceAmount() {
    string finance;
    int financeLength;

    cin >> finance;

    financeLength = finance.length();
    for(int i = 0; i < financeLength; i++) {
        if(finance[i] == ',') {
            finance[i] = '.';
        }
        if(finance[i] == '.' && financeLength - 1 - i > 2) {
            int numberDigitsToDelete = financeLength - 1 - i - 2;
            finance.erase(i + 3, numberDigitsToDelete);
            financeLength = finance.length();
        }
    }
    return atof(finance.c_str());
}
