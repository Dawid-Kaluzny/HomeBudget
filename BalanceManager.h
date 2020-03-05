#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>

#include "Income.h"

using namespace std;

class BalanceManager {
    const int LOGGED_USER_ID;
    vector <Income> incomes;

public:
    BalanceManager(int loggedUserId) : LOGGED_USER_ID(loggedUserId) {};
};

#endif
