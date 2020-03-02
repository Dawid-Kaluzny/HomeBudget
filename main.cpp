#include <iostream>

#include "UserManager.h"

using namespace std;

int main() {
    UserManager userManager;

    userManager.addUser();
    userManager.addUser();
    userManager.addUser();
    userManager.viewAllUsers();
    userManager.addUser();
    userManager.viewAllUsers();
    return 0;
}
