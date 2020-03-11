#ifndef BUDGET_H
#define BUDGET_H

#include <iostream>

#include "AuxiliaryMethods.h"
#include "BalanceManager.h"
#include "UserManager.h"

using namespace std;

class Budget {
    UserManager userManager;
    BalanceManager *balanceManager;
    const string INCOMES_FILE_NAME;
    const string EXPENSES_FILE_NAME;

public:
    Budget(string usersFileName, string incomesFileName, string expensesFileName)
        : userManager(usersFileName), INCOMES_FILE_NAME(incomesFileName), EXPENSES_FILE_NAME(expensesFileName) {
        balanceManager = NULL;
    };
    ~Budget() {
        delete balanceManager;
        balanceManager = NULL;
    }
    void addUser();
    void loginUser();
    void logOutUser();
    void changePasswordLoggedUser();
    bool isUserLogged();
    void addIncome();
    void addExpense();
    void viewBalanceFromCurrentMonth();
    void viewBalanceFromPreviousMonth();
    void viewBalanceFromSelectedPeriod();
    char selectOptionsMainMenu();
    char selectOptionsUserMenu();
};

#endif
