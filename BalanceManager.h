#ifndef BALANCEMANAGER_H
#define BALANCEMANAGER_H

#include <iostream>
#include <vector>

#include "Date.h"
#include "Expense.h"
#include "ExpensesFile.h"
#include "Income.h"
#include "IncomesFile.h"

using namespace std;

class BalanceManager {
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;
    IncomesFile incomesFile;
    ExpensesFile expensesFile;

    Income enterDataNewIncome();
    Expense enterDataNewExpense();
    void viewBalance(int earliestDate, int latestDate);

public:
    BalanceManager(string incomesFileName, string expensesFileName,int loggedUserId) :
        incomesFile(incomesFileName), expensesFile(expensesFileName), LOGGED_USER_ID(loggedUserId) {
        incomes = incomesFile.loadIncomesLoggedUserFromFile(LOGGED_USER_ID);
        expenses = expensesFile.loadExpensesLoggedUserFromFile(LOGGED_USER_ID);
    };
    void addIncome();
    void addExpense();
    void viewBalanceFromCurrentMonth();
    void viewBalanceFromPreviousMonth();
    void viewBalanceFromSelectedPeriod();
};

#endif
