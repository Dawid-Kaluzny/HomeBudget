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

public:
    Budget(string usersFileName) : userManager(usersFileName) {
        balanceManager = NULL;
    };
    ~Budget()
    {
        delete balanceManager;
        balanceManager = NULL;
    }
    void addUser();
    void loginUser();
    void logOutUser();
    void changePasswordLoggedUser();
    bool isUserLogged();
    char selectOptionsMainMenu();
    char selectOptionsUserMenu();
};

#endif
