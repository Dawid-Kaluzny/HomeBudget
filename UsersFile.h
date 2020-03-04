#ifndef USERSFILE_H
#define USERSFILE_H

#include <iostream>
#include <vector>

#include "User.h"
#include "XmlFile.h"

using namespace std;

class UsersFile : public XmlFile {
public:
    UsersFile(string usersFileName) : XmlFile(usersFileName) {};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void addAllUsersToFile(vector <User> &users);
};

#endif
