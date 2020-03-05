#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>

#include "Date.h"
#include "Income.h"
#include "IncomesFile.h"

using namespace std;

class BalanceManager {
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    IncomesFile incomesFile;

    Income enterDataNewIncome();

public:
    BalanceManager(string incomesFileName, int loggedUserId) : incomesFile(incomesFileName), LOGGED_USER_ID(loggedUserId) {
        incomes = incomesFile.loadIncomesLoggedUserFromFile(LOGGED_USER_ID);
    };
    void addIncome();
    void viewAllIncomes();
};

#endif
