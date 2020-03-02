#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"

using namespace std;

class UserManager {
    int loggedUserId;
    vector <User> users;

    User enterNewRecpientData();
    int getNewUserId();
    bool isLoginExists(string login);

public:
    UserManager() {
        loggedUserId = 0;
    }
    void addUser();
    void viewAllUsers();
};

#endif
