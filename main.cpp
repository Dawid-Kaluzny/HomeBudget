#include <iostream>

#include "Budget.h"

using namespace std;

int main() {
    Budget budget("users.xml");

    while (true) {
        if (budget.isUserLogged() == false) {
            switch (budget.selectOptionsMainMenu()) {
            case '1':
                budget.addUser();
                break;
            case '2':
                budget.loginUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in the menu." << endl << endl;
                system("pause");
                break;
            }

        } else {
            switch (budget.selectOptionsUserMenu()) {
            case '6':
                budget.changePasswordLoggedUser();
                break;
            case '7':
                budget.logOutUser();
                break;
            }
        }
    }
    return 0;
}
