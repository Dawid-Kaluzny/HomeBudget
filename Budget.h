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

public:
    Budget(string usersFileName, string incomesFileName) : userManager(usersFileName), INCOMES_FILE_NAME(incomesFileName) {
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
    char selectOptionsMainMenu();
    char selectOptionsUserMenu();
    void viewAllIncomes();
};

#endif
