#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "User.h"
#include "UsersFile.h"

using namespace std;

class UserManager {
    int loggedUserId;
    vector <User> users;
    UsersFile usersFile;

    User enterNewRecpientData();
    int getNewUserId();
    bool isLoginExists(string login);

public:
    UserManager(string usersFileName) : usersFile(usersFileName) {
        users = usersFile.loadUsersFromFile();
        loggedUserId = 0;
    }
    void addUser();
    void viewAllUsers();
};

#endif
