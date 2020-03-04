#ifndef BUDGET_H
#define BUDGET_H

#include <iostream>

#include "AuxiliaryMethods.h"
#include "UserManager.h"

using namespace std;

class Budget {
    UserManager userManager;

public:
    Budget(string usersFileName) : userManager(usersFileName) {};
    void addUser();
    void loginUser();
    void logOutUser();
    void changePasswordLoggedUser();
    bool isUserLogged();
    char selectOptionsMainMenu();
    char selectOptionsUserMenu();
};

#endif
