#include <iostream>

#include "UserManager.h"

using namespace std;

int main() {
    UserManager userManager("users.xml");
    userManager.viewAllUsers();
    userManager.loginUser();

    return 0;
}
