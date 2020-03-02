#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>

#include "User.h"

using namespace std;

class UserManager {
    int loggedUserId;
    vector <User> users;

public:
    UserManager() {
        loggedUserId = 0;
    }
};

#endif
